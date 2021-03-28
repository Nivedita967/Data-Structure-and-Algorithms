// * Algorithm =>
// *  In this question, we first find the next greater on the right as well as on the left for each element. 
// * Then we get the largest area histogram / Largest Rectangle as the product between the two (greater on left & greater on right) . We maximise the result in order to get the largest area. 

#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int main()
{
    int arr[1000000], arr_left[1000000], arr_right[1000000], n, element, total_area, total_width, left_width, right_width, maximum;
    cin >> n;
    stack<int> my_stack_left, my_stack_right;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // * FOR FINDING THE NEXT SMALLER ELEMENT ON THE LEFT

    for (int i = 0; i < n; i++)
    {
        element = arr[i];
        if (my_stack_left.empty() || element > arr[my_stack_left.top()])
        {
            if (my_stack_left.empty())
            {
                arr_left[i] = -1;
            }
            else
            {
                arr_left[i] = my_stack_left.top();
            }
        }
        else
        {
            while (!my_stack_left.empty() && element <= arr[my_stack_left.top()])
            {
                my_stack_left.pop();
            }
            if (my_stack_left.empty())
            {
                arr_left[i] = -1;
            }
            else
            {
                arr_left[i] = my_stack_left.top();
            }
        }
        my_stack_left.push(i);
    }

    // * FOR FINDING THE NEXT SMALLER ELEMENT ON THE RIGHT

    for (int i = n - 1; i >= 0; i--)
    {
        element = arr[i];
        if (my_stack_right.empty() || element > arr[my_stack_right.top()])
        {
            if (my_stack_right.empty())
            {
                arr_right[i] = -1;
            }
            else
            {
                arr_right[i] = my_stack_right.top();
            }
        }
        else
        {
            while (!my_stack_right.empty() && element <= arr[my_stack_right.top()])
            {
                my_stack_right.pop();
            }
            if (my_stack_right.empty())
            {
                arr_right[i] = -1;
            }
            else
            {
                arr_right[i] = my_stack_right.top();
            }
        }
        my_stack_right.push(i);
    }
    maximum = INT_MIN;

    // * FOR FINDING THE MAXIMUM AREA OF THE RECTANGLE

    for (int i = 0; i < n; i++)
    {
        left_width = 0;
        right_width = 0;
        element = arr[i];
        int nsetl = arr_left[i];
        int nsetr = arr_right[i];
        if (nsetl == -1)
        {
            left_width = i - 0;
        }
        if (nsetl != -1)
        {
            left_width = i - nsetl - 1;
        }
        if (nsetr == -1)
        {
            right_width = (n - 1) - i;
        }
        if (nsetr != -1)
        {
            right_width = nsetr - i - 1;
        }
        total_width = left_width + right_width + 1;
        total_area = (element * total_width);
        if (maximum < total_area)
        {
            maximum = total_area;
        }
    }
    cout << maximum << '\n';
}
