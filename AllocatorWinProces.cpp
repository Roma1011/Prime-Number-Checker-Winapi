LRESULT CALLBACK WndProc(HWND hWnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
char x[2]="1";
	switch(Message)
	{
		case WM_CREATE:
		{
            CreateWindow("edit","",WS_VISIBLE|WS_BORDER|WS_CLIPCHILDREN|WS_CHILDWINDOW|ES_CENTER|ES_NUMBER,100,50,100,50,hWnd,(HMENU)1,NULL,NULL);
            CreateWindow("button","check",WS_VISIBLE|WS_CHILDWINDOW,120,100,60,33,hWnd,(HMENU)2,NULL,NULL);
		}
		break;
//---------------------------------
		case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case 1:
                {
                    if(LOWORD(wParam ) == 1&&sig==1||sig2==2)
                    {
						sig2=0;
                        sig=0;
                        SetWindowText(GetDlgItem(hWnd,1),0);
						return 0;
                    }
                }
                break;
                case 2:
                {
                    SendDlgItemMessage(hWnd,1,WM_GETTEXT,sizeof(NumLine),(long)NumLine);
                    Prime(NumLine,hWnd);
                }
                break;
            }
		//ArithmeticalOP(wParam,hWnd,lParam,Message);
		break;
//----------------------------------------
		case WM_KEYDOWN:
		//keyBordNum(wParam,hWnd);
		break;
//----------------------------------
        case WM_CTLCOLOREDIT:
        {
            //HBRUSH hBrush = CreateSolidBrush(RGB(0,0,0));
          //::SelectObject((HDC)wParam, (HGDIOBJ)hBrush);
         }
         break;
//--------------------------------------
//--------------------------------------
/*
		case WM_DRAWITEM:
		{
		DrawItemBtn(lParam);
	//	InvalidateRect(hWnd,0,0);
		//UpdateWindow(hWnd);
		//return TRUE;
		}
		break;
		case WM_VSCROLL:
		//InvalidateRect(hEditWindow,0,0);
		break;
//--------------------------------------------
		case WM_CTLCOLORDLG:
			return (INT_PTR)GetStockObject(GRAY_BRUSH);
		break;
//-----------------------------------
		case WM_SETICON:
		break;
//-----------------------------------
*/
		case WM_CLOSE:
		///DeleteObject((HBRUSH)GetClassLong(hEditWindow,GCL_HBRBACKGROUND));
		//DeleteObject((HBRUSH)GetClassLong(Hexadecimal,GCL_HBRBACKGROUND));
		DestroyWindow(hWnd);
		//return TRUE;
		break;
//----------------------------------
		case WM_DESTROY:
		PostQuitMessage(0);
		break;
//----------------------------------
		default:
			return DefWindowProc(hWnd,Message,wParam,lParam);
	}
return 0;
}
