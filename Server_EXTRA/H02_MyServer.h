//-------------------------------------------------------------------------------------------------
//MY_SERVER_H
//-------------------------------------------------------------------------------------------------
#ifndef MY_SERVER_H
#define MY_SERVER_H
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//CLASS_OF_MY_SERVER
//-------------------------------------------------------------------------------------------------
//MACRO
#define MAX_USER_NUM												MAX_ZONE_NUMBER_NUM
#define MAX_SEND_BUFFER_SIZE										100000
#define MAX_RECV_BUFFER_SIZE										100000
//DEFINE


class MyServer
{

private :

	WSADATA mWsaData;

	SOCKET mSocket;
	
//-------------------------------------------------------------------------------------------------
// 2008.11.18 Kim SungSoo
// Intro : 1. Modify socket address struct
//-------------------------------------------------------------------------------------------------
//	SOCKADDR_IN mAddress;
	struct sockaddr_in mAddress;
//-------------------------------------------------------------------------------------------------


public :

	MyServer( void );

	BOOL Init( int *tResult );
	void Free( void );

//-------------------------------------------------------------------------------------------------
// 2008.11.18 Kim SungSoo
// Intro : 1. Modify network process parameter
//-------------------------------------------------------------------------------------------------
	int PROCESS_FOR_NETWORK( HWND hWnd, WPARAM wPrm, LPARAM lPrm );
	//void PROCESS_FOR_NETWORK(SOCKET *cli_fd, UINT fd_status, void *arg);
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// 2008.11.18 Kim SungSoo
// Intro : 1. Delete timer function (this job is runing CWorkerProcess::check_time())
//				 2. reuse
//-------------------------------------------------------------------------------------------------
  void PROCESS_FOR_TIMER( void );
//-------------------------------------------------------------------------------------------------


	void WRITE_FOR_ERROR( char *tErrorData );
	
//-------------------------------------------------------------------------------------------------
// 2008.11.18 Kim SungSoo
// Intro : 1. Add set socket function
//-------------------------------------------------------------------------------------------------
	void SetSocket(SOCKET listen_socket) { mSocket = listen_socket; }
//-------------------------------------------------------------------------------------------------


};
//INSTANCE
extern MyServer mSERVER;
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------------