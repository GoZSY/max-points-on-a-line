/******************************************************************************
  需要两重循环，第一重循环遍历起始点a，第二重循环遍历剩余点b。
    a和b如果不重合，就可以确定一条直线。
    对于每个点a，构建 斜率->点数 的map。
    (1)b与a重合，以a起始的所有直线点数+1 
    (2)b与a不重合，a与b确定的直线点数+1
*******************************************************************************/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) 
    {
        int max = 0;
        int length = points.size();
        if(length < 3)
            return length;
        for(int i = 0; i < length; ++i)
        {
            int dx;
            int dy;
            int same = 0;//相同的点
            int vertical = 0;//垂直的点的次数
            int normal = 0;//正常的点的次数
            map<double,int> mp;
            for(int j = 0; j < length; ++j)
            {
//这里为什么不考虑一个点遍历了两次是因为same初始化为0
                dx = points[i].x-points[j].x;
                dy = points[i].y-points[j].y;
                if(!dx)
                {
                    if(!dy)
                        same++;
                    else
                        vertical++;
                    continue;
                }
                mp[double(dy)/dx]++;
               
            }
            for(map<double,int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                normal = (it->second > vertical ? it->second : vertical) + same;
                if(normal > max)
                    max = normal;
            }
            if(mp.size() == 0)
                max = same + vertical;
                    
        }
        return max;
    }
};
