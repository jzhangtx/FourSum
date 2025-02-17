// FourSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int Count(const std::vector<int>& v, int n)
{
    int count = 0;
    for (auto i : v)
    {
        if (i == n)
            ++count;
    }

    return count;
}

bool Equal(const std::vector<int>& v1, const std::vector<int>& v2)
{
    for (auto n : v1)
    {
        if (Count(v1, n) != Count(v2, n))
            return false;
    }

    return true;
}

bool Exists(const std::vector<std::vector<int>>& vv, const std::vector<int>& v)
{
    if (vv.empty())
        return false;

    for (auto& vec : vv)
    {
        if (Equal(vec, v))
            return true;
    }

    return false;
}

void HasFourSum(const std::vector<int>& vec, int target, size_t index,
    std::vector<int>& rv, std::vector<std::vector<int>>& result)
{
    if (target == 0 && rv.size() == 4)
    {
        if (!Exists(result, rv))   // this quadruples is what we are looking for.
                                 //  add it to the result
            result.push_back(rv);
        return;
    }
    if (vec.size() == index || rv.size() == 4)
        return;

    for (size_t i = index; i < vec.size(); ++i)
    {
        // no matter if there is a quadruples we are looking for, we will add
        //  the current element to the quadruple vector if there is one, get
        //  the quadruples and then pop the element -- even if a quadruple is
        //  found, we still want to try the next element
        rv.push_back(vec[i]);
        HasFourSum(vec, target - vec[i], i + 1, rv, result);
        rv.pop_back();
    }
}

std::vector<std::vector<int>> FourSum(const std::vector<int>& A, int target)
{
    //std::vector<int> sorted(A);
    //std::sort(sorted.begin(), sorted.end());
    //std::qsort(sorted.data(), sorted.size(), sizeof(decltype(sorted)::value_type),
    //    [](const void* pA, const void* pB)->int
    //    {
    //        const int a = *(reinterpret_cast<const int*>(pA));
    //        const int b = *(reinterpret_cast<const int*>(pB));
    //        if (a > b)
    //            return 1;
    //        if (a == b)
    //            return 0;
    //        return -1;
    //    });

    std::vector<std::vector<int>> result;
    std::vector<int> rv;
    rv.reserve(4);
    HasFourSum(A, target, 0, rv, result);

    return result;
}

void PrintVector(const std::vector<int>& v)
{
    if (v.empty())
        return;

    std::cout << v[0];
    for (auto i = v.cbegin() + 1; i != v.cend(); ++i)
    {
        std::cout << ", " << *i;
    }

    std::cout << std::endl;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count <= 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::cout << "Target: ";
        int k;
        std::cin >> k;

        std::cout << "The quadruples that their sum is " << k << ": " << std::endl;

        std::vector<std::vector<int>> fourSum = FourSum(vec, k);
        for (auto& f : fourSum)
        {
            PrintVector(f);
        }
    }
}
