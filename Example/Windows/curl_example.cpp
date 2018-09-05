#define CURL_STATICLIB //curl ���� �߰� �ؾ� ��ũ ������ �ȳ�
#pragma comment(lib, "ws2_32.lib") //curl ���� �߰� �ؾ� ��ũ ������ �ȳ�
#pragma comment(lib, "wldap32.lib") //curl ���� �߰� �ؾ� ��ũ ������ �ȳ�

#include <curl/curl.h>

#ifdef _DEBUG
#pragma comment(lib, "libcurld.lib") // curl debug lib
#else
#pragma comment(lib, "libcurl.lib") // curl release lib
#endif





int main()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	getchar();
	return 0;
}