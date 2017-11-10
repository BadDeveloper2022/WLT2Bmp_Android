#ifndef _BITMAP_FILE_H
#define _BITMAP_FILE_H
typedef short WORD;
typedef int DWORD;
typedef int LONG;
typedef char BYTE;
/*
1：BMP文件组成
BMP文件由文件头、位图信息头、颜色信息和图形数据四部分组成。
*/
/*
2：BMP文件头（14字节）
BMP文件头数据结构含有BMP文件的类型、文件大小和位图起始位置等信息。
*/

typedef struct tagBITMAPFILEHEADER {
	WORD bfType; // 位图文件的类型，必须为BM(1-2字节）
	DWORD bfSize; // 位图文件的大小，以字节为单位（3-6字节）
	WORD bfReserved1; // 位图文件保留字，必须为0(7-8字节）
	WORD bfReserved2; // 位图文件保留字，必须为0(9-10字节）
	DWORD bfOffBits; // 位图数据的起始位置，以相对于位图（11-14字节）
	// 文件头的偏移量表示，以字节为单位
} BITMAPFILEHEADER;
/*
 *
3：位图信息头（40字节）
BMP位图信息头数据用于说明位图的尺寸等信息
 */
typedef struct tagBITMAPINFOHEADER {
	DWORD biSize; // 本结构所占用字节数（15-18字节）
	LONG biWidth; // 位图的宽度，以像素为单位（19-22字节）
	LONG biHeight; // 位图的高度，以像素为单位（23-26字节）
	WORD biPlanes; // 目标设备的级别，必须为1(27-28字节）
	WORD biBitCount; // 每个像素所需的位数，必须是1（双色），（29-30字节）
	// 4(16色），8(256色）16(高彩色)或24（真彩色）之一
	DWORD biCompression; // 位图压缩类型，必须是 0（不压缩），（31-34字节）
	// 1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
	DWORD biSizeImage; // 位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）
	LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数（39-42字节）
	LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数（43-46字节)
	DWORD biClrUsed; // 位图实际使用的颜色表中的颜色数（47-50字节）
	DWORD biClrImportant; // 位图显示过程中重要的颜色数（51-54字节）
} BITMAPINFOHEADER;
/*
4：颜色表
颜色表用于说明位图中的颜色，它有若干个表项，每一个表项是一个RGBQUAD类型的结构，定义一种颜色。RGBQUAD结构的定义如下：
 */
typedef struct tagRGBQUAD {
    BYTE rgbBlue;// 蓝色的亮度（值范围为0-255)
    BYTE rgbGreen; // 绿色的亮度（值范围为0-255)
    BYTE rgbRed; // 红色的亮度（值范围为0-255)
    BYTE rgbReserved;// 保留，必须为0
} RGBQUAD;
/*
颜色表中RGBQUAD结构数据的个数有biBitCount来确定：
当biBitCount=1,4,8时，分别有2,16,256个表项；
当biBitCount=24时，没有颜色表项。
位图信息头和颜色表组成位图信息，BITMAPINFO结构定义如下：
 */
typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader; // 位图信息头
    RGBQUAD bmiColors[1]; // 颜色表
} BITMAPINFO;
/*
5：位图数据
位图数据记录了位图的每一个像素值，记录顺序是在扫描行内是从左到右，扫描行之间是从下到上。位图的一个像素值所占的字节数：
当biBitCount=1时，8个像素占1个字节；
当biBitCount=4时，2个像素占1个字节；
当biBitCount=8时，1个像素占1个字节；
当biBitCount=24时，1个像素占3个字节,按顺序分别为B,G,R；
Windows规定一个扫描行所占的字节数必须是
4的倍数（即以long为单位），不足的以0填充，
biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) / 8) * bi.biHeight;
具体数据举例：
如某BMP文件开头：
424D 46900000 0000 0000 4600 0000 2800 0000 8000 0000 9000 0000 0100*1000 0300 0000 0090 0000 A00F 0000 A00F0000 0000 00000000 0000*00F8 E007 1F00 0000*02F1 84F1 04F1 84F1 84F1 06F2 84F1 06F2 04F2 86F2 06F2 86F2 86F2 .... ....
读取方法
 */
#endif

