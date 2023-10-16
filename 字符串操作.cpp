////
//// Created by Administrator on 2023/8/24.
////
//#include <iostream>
//#include <cassert>
//using namespace std;
//int custom_strcmp(const char* front, const char* back);
//size_t custom_strlen01 (const char* src);
//size_t custom_strlen02(const char* src);
//size_t custom_strlen03(const char* src);
//char* custom_strcpy(char* dest, const char* src);
//char* custom_strcat(char* dest, const char* src);
//int custom_strncmp(char* front , char* back, size_t count);
//char* custom_strncpy(char* dest, const char* src, size_t count);
//char* custom_strncat(char* dest, const char* src, size_t count);
//char* custom_strncpy01(char* dest, const char* src, int count);
//
//int main()
//{
////    cout<<custom_strcmp("mab", "mbd")<<endl;
////    cout<<custom_strlen01("wojjnibi44")<<endl;
////    cout<<custom_strlen02("wojjnibi545")<<endl;
////    cout<<custom_strlen03("wojjnibi466")<<endl;
//    char dest[30] = "i love you";
//    char src[] = "how about you";
////    cout<<custom_strcpy(dest, src)<<endl;
////    cout<<custom_strcat(dest, src)<<endl;
//    cout<<custom_strncat(dest, src,sizeof src)<<endl;
//    cout << custom_strncpy01(dest, src,6) << endl;
//    cout<<custom_strncat(dest, src,3)<<endl;
////    cout<<custom_strncmp("wer", "werfg",3)<<endl;
//
//    return 0;
//}
//
////字符串比较
//int custom_strcmp(const char* front, const char* back)
//{
//    while(*front == *back && *front)
//    {
//        front++;
//        back++;
//    }
//
//    return *front - *back;
//}
//
////字符长度
//size_t custom_strlen01(const char* src)
//{
//    size_t count = 0;
//    while(*src++ && ++count)
//        ;
//    return count;
//}
//
//size_t custom_strlen02(const char* src)
//{
//    if(*src)
//    {
//        return 1 + custom_strlen02(src+1);
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//size_t custom_strlen03(const char* src)
//{
//    const char* start = src;
//    while(*src++);
//
//    return src-1-start;
//}
//
////字符串copy
//char* custom_strcpy(char* dest, const char* src)
//{
//    char* ret = dest;
//    while((*dest++ = *src++));
//
//    return ret;
//}
//
////字符串拼接
//char* custom_strcat(char* dest, const char* src)
//{
//    char* ret = dest;
//    while(*dest++);
//    dest--;
//    while((*dest++ = *src++));
//
//    return ret;
//}
//
////字符串的前n个比较
//int custom_strncmp(char* front , char* back, size_t count)
//{
//    assert(front && back);
//    while(count-- > 1 && (*front == *back) && *front)
//    {
//        front++;
//        back++;
//    }
//
//    return *front - *back;
//}
//
////
//char* custom_strncpy(char* dest, const char* src, size_t count)
//{
//    char* ret = dest;
//    while(count && (*dest++ = *src++))
//        count--;
//
//    if(count)
//    {
//        while(--count)
//            *dest++ = '\0';
//    }
//    return ret;
//}
//
//
//char* custom_strncpy01(char* dest, const char* src, int count)
//{
//    char* ret = dest;
//    while(count-- && (*dest++ = *src++));
//    if(count == -1)
//        return ret;
//    while(count--)
//        *dest++ = '\0';
//    return ret;
//}
//
//char* custom_strncat(char* dest, const char* src, size_t count)
//{
//    char* ret = dest;
//    while(*dest)
//        dest++;
//    while(count--)
//        if ((*dest++ = *src++) == '\0')
//            return ret;
//    *dest = '\0';
//    return ret;
//}
//
//int custom_strstr(const char* front, const char* back)
//{
//
//
//}