//-------------------------------------------------------------------------------------------------
//MY_GAME_H
//-------------------------------------------------------------------------------------------------
#ifndef MY_GAME_H
#define MY_GAME_H
//-------------------------------------------------------------------------------------------------

//#include "zlib.h"
#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>


//-------------------------------------------------------------------------------------------------
//CLASS_OF_MY_GAME
//-------------------------------------------------------------------------------------------------
//MACRO
#define MAX_COST_INFO_NUM											1000

// @ Cost Info Download @
#define MAX_COST_INFO_CODE_LEN                                      51
#define MAX_COST_INFO_TYPE                                          5
// @

//DEFINE
class MyGame
{

private :
	//-------------------------------------------------------------------------------------------------
	// 2008.11.18 Kim SungSoo
	// Intro : 	1. Modify win32 function to linux c++ 
	//					2. Create that load file then return string
	//-------------------------------------------------------------------------------------------------	
	BOOL GetOneValueFromFile( HANDLE hFile, int tBufferSize, char *tBuffer );
	// @ Cost Info Download @
	//int GetOneValueFromFile(const char *pBuffer , int iParsorIndex);
	bool GetOneValueFromFile(const char *pBuffer , int iParsorIndex, int *tResult);
	// @
	bool GetOneValueFromFile(char *pValue , const char *pBuffer , int iParsorIndex);
	//-------------------------------------------------------------------------------------------------	

public :

	DWORD mTickCount;

	int mTotalCostInfoNum;
	// @ Cost Info Download @
	// ���� ���� �߰�.
	int mCostInfoValue[MAX_COST_INFO_NUM][MAX_COST_INFO_TYPE]; //[0]::����,[1]::������,[2]::����,[3]::�Ǹſ���,[4]::��������(1���, 2����, 3���, 4��ȭ)

	bool mIsSellCashItem;
	int mCashItemInfoVersion;           // COST_INFO.TXT�� ����
	int mCashItemInfo[4][14][10][4];    // Ŭ���̾�Ʈ���� ����ϴ� ĳ�� ������ ���� ����


	

	int GetCostInfoVersion();
	bool LoadCostInfo(int *pTotalCostInfoNum, int *pVersion, int tCostInfoValue[MAX_COST_INFO_NUM][MAX_COST_INFO_TYPE], char tCostInfoCode[MAX_COST_INFO_NUM][MAX_COST_INFO_CODE_LEN]);
	bool MakeCashItemInfo(int tCashItemInfo[4][14][10][4], const int tCostInfoValue[MAX_COST_INFO_NUM][MAX_COST_INFO_TYPE], int totalCostInfoNum);
	// @
	char mCostInfoCode[MAX_COST_INFO_NUM][MAX_COST_INFO_CODE_LEN];

	MyGame( void );

	BOOL Init( void );
	void Free( void );

	int UpdateCashItem(void);
	int UpdateBloodItem(void);


	int mTotalCostBloodInfoNum;
	int mBloodCashItemInfo[4][50][3];
	int mBloodInfoValue[200][4];
	char mBloodInfoCode[200][MAX_COST_INFO_CODE_LEN];
	bool LoadBloodInfo(int* ptotalBloodInfoNum, int tBlooInfoValue[200][4], char tBlooInfoCode[200][MAX_COST_INFO_CODE_LEN]);
	bool MakeBloodItemInfo(int tBloodItemInfo[4][50][3], const int tCostBloodValue[50][4], int totalBloodInfoNum);

};
//INSTANCE
extern MyGame mGAME;
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
#endif
//-------------------------------------------------------------------------------------------------
