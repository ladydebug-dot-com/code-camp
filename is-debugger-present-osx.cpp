#include <stdio.h>
#include <unistd.h>
#include <sys/sysctl.h>
int main(int n, char ** s)
{
   char procname[255];
   int mib[4] = { 0, 0, 0, 0 };
   size_t len = 2;
   kinfo_proc kp;
   sysctlnametomib("kern.procname", mib, &len);
   len = sizeof(procname);
   int iError = sysctl(mib,2,procname,&len, NULL, 0);
   if(iError == 0)
   {
      printf("Process name: %s\n", procname);\
      size_t len = 4;
      sysctlnametomib("kern.proc.pid", mib, &len);
      mib[3] = getpid();
      len = sizeof(kp);
      iError = sysctl(mib, 4, &kp, &len, NULL, 0);
      if(iError != 0)
      {
         perror("Error");
      } else {
         if(kp.kp_proc.p_flag & P_TRACED)
         {
            printf("The \"%s\" process is under debugger\n",procname);
         }
      }
   }
   else
   {
      perror("Error");
   }
   return 0;
}




