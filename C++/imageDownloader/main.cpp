//
//  main.cpp
//  imageDownloader
//
//  Created by Harry O'Brien on 11/10/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <string>

size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata)
{
	FILE* stream = (FILE*)userdata;
	if (!stream)
	{
		printf("!!! No stream\n");
		return 0;
	}
	
	size_t written = fwrite ((FILE*)ptr, size, nmemb, stream);
	return written;
}

bool download_jpeg(char* url)
{
	FILE* fp = fopen("out.jpg", "wb");
	if (!fp)
	{
		std::cout << "!!! Failed to create file on the disk !!!" << std::endl;
		return false;
	}
	
	CURL* curlCtx = curl_easy_init();
	curl_easy_setopt(curlCtx, CURLOPT_URL, url);
	curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
	curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, 1);
	
	CURLcode rc = curl_easy_perform(curlCtx);
	if (rc)
	{
		printf("!!! Failed to download: %s\n", url);
		return false;
	}
	
	long res_code = 0;
	curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
	if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK))
	{
		std::cout << "!!! Response code: " << res_code << " !!!" << std::endl;
		return false;
	}
	
	curl_easy_cleanup(curlCtx);
	
	fclose(fp);
	
	return true;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <url>\n", argv[0]);
		return -1;
	}
	
	if (!download_jpeg(argv[1]))
	{
		printf("!! Failed to download file: %s\n", argv[1]);
		return -1;
	}
	
	return 0;
}
