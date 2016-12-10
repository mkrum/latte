/* measure.c
   David Chiang 

   with borrowing from:

   getPeakRSS (http://nadeausoftware.com/articles/2012/07/c_c_tip_how_get_process_resident_set_size_physical_memory_use)
   David Robert Nadeau 
   Creative Commons Attribution 3.0 Unported License
   http://creativecommons.org/licenses/by/3.0/deed.en_US

   GNU time (https://www.gnu.org/software/time/)
   David Keppel, David MacKenzie, Arne Henrik Juul, and Francois Pinard
   Copyright (C) 1990, 91, 92, 93, 96 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#if defined(__APPLE__) && defined(__MACH__)
const int memory_unit = 1;
#else
const int memory_unit = 1024;
#endif

void perror_exit() {
  perror(NULL);
  exit(1);
}

int main (int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "usage: measure command [argument ...]\n");
    exit(1);
  }

  struct stat s;
  if (stat(argv[1], &s) != 0) perror_exit();
  if (!(s.st_mode & S_IXUSR)) {
    errno = EACCES;
    perror_exit();
  }

  pid_t pid = fork();
  if (pid < 0) perror_exit();
  if (pid == 0) {
    execvp(argv[1], argv+1);
    /* If the execvp failed: */
    perror_exit();
  }

  int status;
  struct rusage ru;
  pid_t caught;
  while ((caught = wait3(&status, 0, &ru)) != pid)
    if (caught == -1) perror_exit();

  if (WIFSIGNALED(status))
    psignal(WTERMSIG(status), NULL);

  float time = ru.ru_utime.tv_sec + ru.ru_utime.tv_usec/1000000. + 
               ru.ru_stime.tv_sec + ru.ru_stime.tv_usec/1000000.;
  printf("%f seconds\t", time);

  float memory = (float)ru.ru_maxrss * memory_unit / (1024*1024);
  printf("%f Mbytes\n", memory);
}
