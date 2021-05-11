#include <vector>

template <bool side, typename T>
void merge(std::vector<T>& final, const std::vector<T>& left, const std::vector<T>& right)
{
    if (side == 1)  // порядок возрастания
    {
        int l_min = 0;
        int r_min = 0;
        int min = 0;

        while ((l_min < left.size()) && (r_min < right.size()))
        {
            if (left[l_min] < right[r_min])
            {
                final[min] = left[l_min];
                min++;
                l_min++;
            }
            else
            {
                final[min] = right[r_min];
                min++;
                r_min++;
            }
        }

        while (l_min < left.size())
        {
            final[min] = left[l_min];
            min++;
            l_min++;
        }

        while (r_min < right.size())
        {
            final[min] = right[r_min];
            min++;
            r_min++;
        }
    }
    else  // порядок убывания
    {
        int l_max = 0;
        int r_max = 0;
        int max = 0;

        while ((l_max < left.size()) && (r_max < right.size()))
        {
            if (left[l_max] < right[r_max])
            {
                final[max] = right[r_max];
                max++;
                r_max++;
            }
            else
            {
                final[max] = left[l_max];
                max++;
                l_max++;
            }
        }

        while (l_max < left.size())
        {
            final[max] = left[l_max];
            max++;
            l_max++;
        }

        while (r_max < right.size())
        {
            final[max] = right[r_max];
            max++;
            r_max++;
        }
    }

}

template <bool side, size_t num_threads, typename T>
void merge_sort(const std::vector<T>& vec, size_t start, size_t finish, std::vector<T>& result)
{
    if (vec.size() < 2)
        return;

    size_t middle = (finish - start) / 2;
    std::vector<T> left(middle);
    std::vector<T> right(vec.size() - middle);

    for (size_t i = 0; i < middle ; i++)
        left[i] = vec[i];
    for (size_t i = 0; i < vec.size() - middle; i++)
        right[i] = vec[middle - 1 + i];

    merge_sort<side, num_threads>(left);
    merge_sort<side, num_threads>(right);
    merge<side, T>(vec, left, right);
}
