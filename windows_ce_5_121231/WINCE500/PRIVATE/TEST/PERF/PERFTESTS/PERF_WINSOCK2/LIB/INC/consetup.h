//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of your Microsoft Windows CE
// Source Alliance Program license form.  If you did not accept the terms of
// such a license, you are not authorized to use this source code.
//
// consetup.h

#ifndef _CONSETUP_H_
#define _CONSETUP_H_

const DWORD MAX_SERVER_NAME_LEN = MAX_PATH;

WORD GetSocketLocalPort(SOCKET sock);

INT ListenSocket(
    WORD wIpVer,
    INT protocol,               // SOCK_STREAM or SOCK_DGRAM
    WORD* pwListenPort,         // on which port to listen on - if 0, then will fill-in with port number selected
    SOCKET* ListeningSocks[],
    INT* pNumListeningSocks,
    DWORD* pdwWSAError);

SOCKET ConnectSocketByAddrFromSocket(
    SOCKET sock,                // will use this socket (instead of creating a new one) if in_sock = INVALID_SOCKET
    SOCKET addr_sock,           // socket from which to derive address
    WORD wServerPort,
    WORD wIpVer,
    INT protocol,               // SOCK_STREAM or SOCK_DGRAM
    BOOL fHardClose,
    LPSOCKADDR lpLocalAddrOut, DWORD* pdwLocalAddrOutLen,   // will fill this in if not NULL
    LPSOCKADDR lpRemoteAddrOut, DWORD* pdwRemoteAddrOutLen, // will fill this in if not NULL
    DWORD* pdwWSAError);

SOCKET ConnectSocketByAddr(
    SOCKET sock,                // will use this socket (instead of creating a new one) if sock = INVALID_SOCKET
    LPSOCKADDR pServerAddr, INT nServerAddrLen,
    WORD wServerPort,
    WORD wIpVer,
    INT protocol,               // SOCK_STREAM or SOCK_DGRAM
    BOOL fHardClose,
    LPSOCKADDR lpLocalAddrOut, DWORD* pdwLocalAddrOutLen,   // will fill this in if not NULL
    LPSOCKADDR lpRemoteAddrOut, DWORD* pdwRemoteAddrOutLen, // will fill this in if not NULL
    DWORD* pdwWSAError);

SOCKET ConnectSocket(
    SOCKET sock,                // will use this socket (instead of creating a new one) if sock = INVALID_SOCKET
    TCHAR* szServerName,
    WORD wServerPort,
    WORD wIpVer,
    INT protocol,               // SOCK_STREAM or SOCK_DGRAM
    BOOL fHardClose,
    LPSOCKADDR lpLocalAddrOut, DWORD* pdwLocalAddrOutLen,   // will fill this in if not NULL
    LPSOCKADDR lpRemoteAddrOut, DWORD* pdwRemoteAddrOutLen, // will fill this in if not NULL
    DWORD* pdwWSAError);

SOCKET AcceptConnection(
    SOCKET ListeningSockArray[],
    INT nListeningSockCount,
    HANDLE hStopEvent,
    DWORD dwTimeoutMs,
    DWORD* pdwWSAError);

void DisconnectSocket(SOCKET sock);

BOOL ApplySocketSettings(
    SOCKET sock,
    INT sock_type,
    BOOL nagle_off,     // if FALSE will leave at default
    INT send_buf,       // if < 0 will leave at default
    INT recv_buf,       // if < 0 will leave at default
    DWORD* pdwWSAError);

#endif // #ifndef _CONSETUP_H_

