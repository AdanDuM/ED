#Grupo 5
####Membros
* Tiago Augusto Fontana (11200662) <br>
* William Kraemer Aliaga (11200669)

-------------------------------------------
#System Object Destruction
<p style='text-align: justify;'>
EPOS abstracts system entities as ordinary C++ objects, thus promoting usability. At some points, however, the semantics of operating system and programming language do not seem to fit together easily. Consider for instance the case in which a system abstraction (say thread), created by the application programmer with new, is destroyed by the operating system (e.g. exit). Or the counterpart situation: the application programmer deleting a thread that is currently being manipulated by the operating system.
</p>

<p style='text-align: justify;'>
A careful binding between programming language and operating system must be defined to prevent undesirable side effects.
</p>

###To do

<p style='text-align: justify;'>
Modify the implementation of this didactic version of OpenEPOS such that the delete C++ operation preserves system consistency at the same time it honors the programming language semantics.
</p>

#Solução Proposta

###Destrução de Thread
<p style='text-align: justify;'>
Para garantir a consistẽncia do sistema ao realizar invocações dos destrutores ao utilizar delete, precisamos garantir que os destrutores garantam a consistencia do sistema.
<br>
Para isso começamos modificando o destrutor da classe Thread, verificando que a thread em questão seja
 removida especificamente da sua respectiva fila de acordo com seu estado. Também garantimos que a thread
 _ joining seja liberada, assim ela não se mantem bloqueada eternamente. Se o estado for FINISHING, a thread
 já executou o metodo exit, com isso garantimos a liberação de todos os recursos da thread.
</p>
<br>


####thread.cc

```c++

Thread::~Thread()
{
    lock();

    db<Thread>(TRC) << "~Thread(this=" << this
                    << ",state=" << _state
                    << ",priority=" << _link.rank()
                    << ",stack={b=" << _stack
                    << ",context={b=" << _context
                    << "," << *_context << "})" << endl;

    if(_state != FINISHING){
    	if(_joining) {
    		// se for FINISHING resume ocorrerá no método "exit"
    	   _joining->resume();
    	   _joining = 0;
    	}
    	_thread_count--;
    }

    if(_state == READY){
    	_ready.remove(this);
    }else if(_state == SUSPENDED){
    	_suspended.remove(this);
    }else if( _state == WAITING){
    	if(_waiting) // evitar remoção caso tenha passado pelo wakeup/wakeup_all
    		_waiting->remove(this);
    }else if(_state == RUNNING){
    	exit(-1);
    }
    //Se estado for FINISHING, siginifica que a thread ja executou o exit
    // com isso garantimos no exit a liberação de todos os recursos da thread.

    unlock();

    kfree(_stack);
}
```
### Destrução de Sincronizadores do sistema
<p style='text-align: justify;'>
Para possibilitar que ferramentas formais de verificação de corretude do software,
foram inseridas asserções nos destrutores dos sinalizadores do sistema. Estas asserções
verificam se a fila dos sincronizadores está vazia antes da deleção do sincronizador.
Caso a fila não esteje vazia, ocorrerá um erro de compilação do código fonte,
evitando assim problemas de semantica na utilização de sincronizadores. <br>
Com as asserções, fica claro ao programador que para destruir um sincronizador é
necessario que esses não possuam threads aguardando-os pois se houver elas irao ficar
bloqueados eternamente
</p>

####mutex.cc

```c++
Mutex::~Mutex()
{
    db<Synchronizer>(TRC) << "~Mutex(this=" << this << ")" << endl;
    //Garantir em tempo de compilação que a fila do mutex não possua elementos.
    //Possibilitando assim a deleção do mutex, exclusivamente se não houver
    //   threads esperando neste recurso
    assert(_queue._size == 0);
}
```

####semaphore.cc

```c++
Semaphore::~Semaphore()
{
    db<Synchronizer>(TRC) << "~Semaphore(this=" << this << ")" << endl;
    assert(_queue._size == 0);
}
```

####condition.cc

```c++
Condition::~Condition() {
    db<Synchronizer>(TRC) << "~Condition(this=" << this << ")" << endl;
    assert(_queue._size == 0);
}
```
### Destrução de Alarmes
<p style='text-align: justify;'>
Alarmes são inseridos em uma fila relativa de requests na criação. Por isso foi pensado a questão da remoção ao ser deletado.
No destrutor do alarme já se cuida da remoção dele da fila de requests, conforme foi identificado.
Também pensamos em deletar o Handler do alarme, porém percebemos que este pode ser
comum a outros alarmes. Além de ser boa prática que o realizador da criação seja encarregado pela deleção.
</p>

#####alarm.cc

```c++

Alarm::~Alarm()
{
    lock();

    db<Alarm>(TRC) << "~Alarm(this=" << this << ")" << endl;

    _request.remove(this);

    unlock();
}
```
