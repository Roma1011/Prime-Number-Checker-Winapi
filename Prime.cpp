void Prime(char* NumLine,HWND hWnd)
{
bool is_prime = true;
int n,i;
n=atoi((char*)NumLine);
  // 0 and 1 are not prime numbers
  if(n == 0 || n == 1)
  {
    is_prime = false;
  }
  // loop to check if n is prime
	  for (i = 2; i <= n/2; ++i)
	  {
		if (n % i == 0)
        {
		  is_prime = false;
		  break;
		}
	  }
  if (is_prime)
  {
    SetWindowText(GetDlgItem(hWnd,1),Pr);
   //SendDlgItemMessage(hWnd,1,WM_SETTEXT,NULL,(long)Pr);
   sig=1;
  }
  else
  {
    SetWindowText(GetDlgItem(hWnd,1),Np);
    sig2=2;
  }
  return;
}
