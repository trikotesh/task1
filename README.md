						#TASK 1
#program name 
exec.c(program 1) 
#HEADER FILES:
stdio.h
stdlib.h
sys/wait.h
unistd.h
#SYSTEM CALL:
fork()
wait()
execvp()
#RETURN VALUE
 On  success, the PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.
#DESCRIPTION
To change the process image used one of the exec family system call
The  exec()  family  of  functions replaces the current process image with a new process image.
fork()creates  a  new  process by duplicating the calling process.  The new process is referred to as the child process.  The calling process is referred to as the parent process.


#program name
simthreads.c (program 2)
#HEADER FILES:
stdio.h
unistd.h
pthread.h
#SYSTEM CALL:
sleep()
#DESCRIPTION
To execute two threads simultaneously, created two threads 
sleep() system call Pause  for  NUMBER  seconds.

#program name
kill3.c(program 3)
#HEADER FILES:
stdio.h
stdlib.h
string.h
signal.h
#SYSTEM CALL:
kill()
#DESCRIPTION
Implemented own kill system call functionality
The  default  signal  for  kill  is TERM.  Use -l or -L to list available signals.  Particularly useful signals include HUP, INT, KILL,
STOP, CONT, and 0.  Alternate signals may be specified in three ways: -9, -SIGKILL or -KILL.  Negative PID values may be used to choose
whole  process  groups;  see  the PGID column in ps command output.  A PID of -1 is special; it indicates all processes except the kill process itself and init.

#program name

