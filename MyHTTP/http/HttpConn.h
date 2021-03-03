#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/uio.h>
#include "../webserver/WebServer.h"

#define HTTP_CONTINUE                  100
#define HTTP_SWITCHING_PROTOCOLS       101
#define HTTP_PROCESSING                102

#define HTTP_OK                        200
#define HTTP_CREATED                   201
#define HTTP_ACCEPTED                  202
#define HTTP_NO_CONTENT                204
#define HTTP_PARTIAL_CONTENT           206

#define HTTP_SPECIAL_RESPONSE          300
#define HTTP_MOVED_PERMANENTLY         301
#define HTTP_MOVED_TEMPORARILY         302
#define HTTP_SEE_OTHER                 303
#define HTTP_NOT_MODIFIED              304
#define HTTP_TEMPORARY_REDIRECT        307
#define HTTP_PERMANENT_REDIRECT        308

#define HTTP_BAD_REQUEST               400
#define HTTP_UNAUTHORIZED              401
#define HTTP_FORBIDDEN                 403
#define HTTP_NOT_FOUND                 404
#define HTTP_NOT_ALLOWED               405
#define HTTP_REQUEST_TIME_OUT          408
#define HTTP_CONFLICT                  409
#define HTTP_LENGTH_REQUIRED           411
#define HTTP_PRECONDITION_FAILED       412
#define HTTP_REQUEST_ENTITY_TOO_LARGE  413
#define HTTP_REQUEST_URI_TOO_LARGE     414
#define HTTP_UNSUPPORTED_MEDIA_TYPE    415
#define HTTP_RANGE_NOT_SATISFIABLE     416
#define HTTP_MISDIRECTED_REQUEST       421
#define HTTP_TOO_MANY_REQUESTS         429

class HttpConn
{
public:
	HttpConn(int fd,sockaddr_in clientaddr);
	~HttpConn();
	ssize_t Read();
	ssize_t Write();
	int WriteBytesCount();
	

public:
	static const char* srcDir;

private:
	int m_fd;
	struct sockaddr_in addr;
	bool isClose;
	int iovCnt;
	struct  iovec	iov[2];

};
