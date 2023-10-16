////
//// Created by Administrator on 2023/8/23.
////
//#include <iostream>
//int binary_search(const int* start, int size, int quest){
//    int left = 0;
//    int right = size-1;
//    int mid = left + (right-left)/2;
//    while(left <= right)
//    {
//        if(quest > start[mid])
//        {
//            left = mid + 1;
//            mid = left + (right-left)/2;
//        }
//        else if(quest < start[mid])
//        {
//            right = mid -1;
//            mid = left + (right-left)/2;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return -1;
//}
//
//
//int main(){
//    using namespace std;
//    int array[] = {1,2,3,6,7,10,56,58,89,567,890};
//    int ret = binary_search(array, sizeof array / sizeof array[0], 890);
//    if (ret > 0)
//    {
//       cout << "找到了," <<" 在索引"<<ret<<"处"<<endl;
//    }
//    else
//    {
//       cout << "未找到";
//    }
//    return 0;
//}