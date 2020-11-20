#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void really_sleep (unsigned secs)
{
  do {
    secs = sleep (secs);
    printf ("sleep returned %d\n", secs);
  } while (secs > 0);
}

#define pprintf(format, ...) printf ("[PID %d] " format, getpid(), ##__VA_ARGS__)

void my_sig_handler (int sig)
{
  pprintf ("I received signal %s, but I don't care\n", strsignal (sig));
}

int main (int argc, char *argv[])
{
  struct sigaction sa;

  sa.sa_flags = SA_RESTART;
  sigemptyset (&sa.sa_mask);
  sa.sa_handler = my_sig_handler;

  sigaction (SIGINT, &sa, NULL);

  sigset_t m, old;

  sigemptyset (&m);
  sigaddset (&m, SIGINT);
  sigprocmask (SIG_BLOCK, &m, &old);
  printf ("Any ^C will be postponed\n");

  really_sleep (5);

  printf ("^C are allowed again\n");
  sigprocmask (SIG_SETMASK, &old, NULL);

  really_sleep (5);

  printf ("End of program\n");

  return 0;
}