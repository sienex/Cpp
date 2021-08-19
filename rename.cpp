#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<io.h>
#include<Windows.h>
#define MAX 256

using namespace std;



int main()
{
	char FilePath[MAX] = { 0 };
	char oldPath[MAX] = { 0 };
	char dir[MAX] = "C:\\Users\\I\\Desktop\\1\\";
	char newPath[MAX] = {0};
	char oldname[MAX] = { 0 };
	char newname[MAX][MAX] = { "垂直1.jpg","水平1.jpg","垂直2.jpg" ,"水平2.jpg","垂直3.jpg",
		"水平3.jpg","垂直4.jpg","水平4.jpg","垂直5.jpg","水平5.jpg","垂直6.jpg","水平6.jpg",
		"垂直7.jpg","水平7.jpg","垂直8.jpg","水平8.jpg","垂直9.jpg","水平9.jpg","垂直10.jpg",
		"水平10.jpg","垂直11.jpg","水平11.jpg","垂直12.jpg","水平12.jpg" };
	int len = 0;
	int i = 0;
	sprintf_s(FilePath, "%s%s", dir, "*.*");
	

	long handle = 0;

	struct _finddata_t fileinfo;

	handle = _findfirst(FilePath, &fileinfo);
	
	

	if (handle == -1)
	{
		printf("no find file\n");
		return 0;
	}

	do {
		len = strlen(fileinfo.name);

		if (len>0)
		{
			sprintf_s(oldPath, "%s%s", dir, fileinfo.name);
			sprintf_s(newPath, "%s%s", dir, newname[i++]);

			MoveFile(oldPath, newPath);
		}
	} while (_findnext(handle, &fileinfo) == 0);

	_findclose(handle);

	printf("success\n");
	

	return 0;
}
