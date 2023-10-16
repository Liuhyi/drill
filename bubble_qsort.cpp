////
//// Created by Administrator on 2023/8/23.
////
//#include <iostream>
//
//using namespace std;
//void swap(char* element1, char* element2, int width);
//int compare_int(void* element1, void* element2);
//void test_01();
//void test_02();
//struct classmate {
//    int age;
//    int stature;
//    char name[20];
//};
//
//
//int main(){
//
//    test_01();
//
//    test_02();
//
//    return 0;
//}
//
//
//
//void bubble_qsort(void* base, int size, int width, int (*compare) (void* element1, void* element2))
//{
//    for (int i = 0; i < size-1; i++)
//    {
//        int flag = 1;
//        for ( int j = 0; j < size -1-i; j++)
//        {
//            if (compare((char*)base + j * width, (char*)base + (j+1) * width) < 0)
//            {
//                swap((char*)base + j * width, (char*)base + (j+1) * width, width);
//                flag = 0;
//            }
//        }
//        if (flag)
//        {
//            break;
//        }
//    }
//
//}
//
//void swap(char* element1, char* element2, int width)
//{
//    while(width--)
//    {
//        char temp = *element1;
//        *element1 = *element2;
//        *element2 = temp;
//        element1++;
//        element2++;
//    }
//}
//
//int compare_int(void* element1, void* element2){
//
//    return *(int*)element1 - *(int*)element2;
//}
//
//int compare_classmate_by_stature(void* element1, void* element2){
//
//    return ((classmate*)element1) -> stature -  ((classmate*)element2)-> stature;
//}
//
//int compare_string(char* element1, char* element2)
//{
//    while((*element1 == *element2) && (*element1 != '\0'))
//    {
//        element1++;
//        element2++;
//    }
//    return *element1 - *element2;
//}
//
//int compare_classmate_by_age(void* element1, void* element2){
//
//    return ((classmate*)element1) -> age -  ((classmate*)element2)-> age;
//}
//
//int compare_classmate_by_name(void* element1, void* element2){
//
//    return compare_string(((classmate*)element1) -> name,((classmate*)element2)-> name);
//}
//
//
//void test_01()
//{
//    int array[] = {1,5,67,34,546,57643,23,56,88,45,67,565,
//                   34,3524,34,56,34,546,2435,768,6868,5757,46};
//    bubble_qsort(array, sizeof array / sizeof array[0], 4, compare_int );
//    for (int j : array)
//    {
//        cout << j <<" ";
//    }
//    cout<<endl;
//}
//
//void test_02() {
//    classmate lhz = {21, 173, "ÁõºêÖ¾"};
//    classmate pk = {21, 170, "Åí¿­"};
//    classmate zsy = {20, 168, "Ö£Ë¼Ô´"};
//    classmate yjr = {22, 183, "Ô¬¼Òî£"};
//    classmate lxy = {22, 174, "ÁõÏéÓî"};
//    classmate lhy = {20, 168, "ÁõºÆÓî"};
//    classmate my = {20, 175, "Ä²ÑÒ"};
//    classmate whl = {22, 175, "ÍõºêÁÖ"};
//    classmate ybf = {20, 165, "Ô¬²©·å"};
//    classmate hx = {30, 169, "º«ÐÅ"};
//    classmate zgl = {45, 185, "Öî¸ðÁÁ"};
//    classmate lb = {54, 176, "Áõ±¸"};
//    classmate classmates[] = {lhz, zsy, yjr, lxy, lhy, my, whl, ybf,pk, hx,
//                              lb,zgl};
//
//    bubble_qsort(classmates, sizeof classmates / sizeof classmates[0], sizeof classmates[0],
//                 compare_classmate_by_age);
//    for (const classmate& j : classmates)
//    {
//        cout <<"ÐÕÃû:"<<j.name<<"\t"<<"Éí¸ß: "<<j.stature<<" ÄêÁä: "<< j.age<<" "<<endl;
//    }
//
//}
//
