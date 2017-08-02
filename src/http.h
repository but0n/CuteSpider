#ifndef HTTP_H
#define HTTP_H


//	From https://www.w3.org/Protocols/rfc2616/rfc2616-sec6.html
//	Response
//
//	After receiving and interpreting a request message, a server responds with an HTTP response message.
//
//	Response	=	Status-Line					; Section 6.1
//					*(( general-header			; Section 4.5
//					 | response-header			; Section 6.2
//					 | entity-header ) CRLF)	; Section 7.1
//					CRLF
//					[ message-body ]			; Section 7.2

// Status-Line = HTTP-Version SP Status-Code SP Reason-Phrase CRLF
#define CRLF											"\r\n"
//	- HTTP-Version
#define HTTP_VERSION									"HTTP/1.1 "
//	- Status-Code
#define HTTP_STATUS_LINE_Continue						HTTP_VERSION"100 Continue"CRLF
#define HTTP_STATUS_LINE_SwitchingProtocols				HTTP_VERSION"101 Switching Protocols"CRLF
#define HTTP_STATUS_LINE_OK								HTTP_VERSION"200 OK"CRLF
#define HTTP_STATUS_LINE_Created						HTTP_VERSION"201 Created"CRLF
#define HTTP_STATUS_LINE_Accepted						HTTP_VERSION"202 Accepted"CRLF
#define HTTP_STATUS_LINE_NonAuthoritativeInformation	HTTP_VERSION"203 Non-Authoritative Information"CRLF
#define HTTP_STATUS_LINE_NoContent						HTTP_VERSION"204 No Content"CRLF
#define HTTP_STATUS_LINE_ResetContent					HTTP_VERSION"205 Reset Content"CRLF
#define HTTP_STATUS_LINE_PartialContent					HTTP_VERSION"206 Partial Content"CRLF
#define HTTP_STATUS_LINE_MultipleChoices				HTTP_VERSION"300 Multiple Choices"CRLF
#define HTTP_STATUS_LINE_MovedPermanently				HTTP_VERSION"301 Moved Permanently"CRLF
#define HTTP_STATUS_LINE_Found							HTTP_VERSION"302 Found"CRLF
#define HTTP_STATUS_LINE_SeeOther						HTTP_VERSION"303 See Other"CRLF
#define HTTP_STATUS_LINE_NotModified					HTTP_VERSION"304 Not Modified"CRLF
#define HTTP_STATUS_LINE_UseProxy						HTTP_VERSION"305 Use Proxy"CRLF
#define HTTP_STATUS_LINE_TemporaryRedirect				HTTP_VERSION"307 Temporary Redirect"CRLF
#define HTTP_STATUS_LINE_BadRequest						HTTP_VERSION"400 Bad Request"CRLF
#define HTTP_STATUS_LINE_Unauthorized					HTTP_VERSION"401 Unauthorized"CRLF
#define HTTP_STATUS_LINE_PaymentRequired				HTTP_VERSION"402 Payment Required"CRLF
#define HTTP_STATUS_LINE_Forbidden						HTTP_VERSION"403 Forbidden"CRLF
#define HTTP_STATUS_LINE_NotFound						HTTP_VERSION"404 Not Found"CRLF
#define HTTP_STATUS_LINE_MethodNotAllowed				HTTP_VERSION"405 Method Not Allowed"CRLF
#define HTTP_STATUS_LINE_NotAcceptable					HTTP_VERSION"406 Not Acceptable"CRLF
#define HTTP_STATUS_LINE_ProxyAuthenticationRequired	HTTP_VERSION"407 Proxy Authentication Required"CRLF
#define HTTP_STATUS_LINE_RequestTimeout					HTTP_VERSION"408 Request Time-out"CRLF
#define HTTP_STATUS_LINE_Conflict						HTTP_VERSION"409 Conflict"CRLF
#define HTTP_STATUS_LINE_Gone							HTTP_VERSION"410 Gone"CRLF
#define HTTP_STATUS_LINE_LengthRequired					HTTP_VERSION"411 Length Required"CRLF
#define HTTP_STATUS_LINE_PreconditionFailed				HTTP_VERSION"412 Precondition Failed"CRLF
#define HTTP_STATUS_LINE_RequestEntityTooLarge			HTTP_VERSION"413 Request Entity Too Large"CRLF
#define HTTP_STATUS_LINE_RequestURITooLarge				HTTP_VERSION"414 Request-URI Too Large"CRLF
#define HTTP_STATUS_LINE_UnsupportedMediaType			HTTP_VERSION"415 Unsupported Media Type"CRLF
#define HTTP_STATUS_LINE_Requestedrangenotsatisfiable	HTTP_VERSION"416 Requested range not satisfiable"CRLF
#define HTTP_STATUS_LINE_ExpectationFailed				HTTP_VERSION"417 Expectation Failed"CRLF
#define HTTP_STATUS_LINE_InternalServerError			HTTP_VERSION"500 Internal Server Error"CRLF
#define HTTP_STATUS_LINE_NotImplemented					HTTP_VERSION"501 Not Implemented"CRLF
#define HTTP_STATUS_LINE_BadGateway						HTTP_VERSION"502 Bad Gateway"CRLF
#define HTTP_STATUS_LINE_ServiceUnavailable				HTTP_VERSION"503 Service Unavailable"CRLF
#define HTTP_STATUS_LINE_GatewayTimeout					HTTP_VERSION"504 Gateway Time-out"CRLF
#define HTTP_STATUS_LINE_HTTPVersionnotsupported		HTTP_VERSION"505 HTTP Version not supported"CRLF

#endif