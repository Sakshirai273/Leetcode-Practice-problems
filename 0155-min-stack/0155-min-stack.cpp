#include<stack>
#include<limits.h>
class MinStack {
    stack<long> s;
    long mini ;
public:
     MinStack() {
         
    }
   
    void push(int val) {
        if (s.empty())  {
            s.push(val);
            mini= val;
        }
        else
        {
            if(val<mini)
            {
                s.push(2ll*val - mini);
                mini= val;
            }
            else
            {
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        // stack top can never be smaller than mn, if it is then it indicates a flag which means before popping, you have to update mn
        if(s.top() < mini){
            // mn = 2*mn - s.top()
            mini = 2ll*mini - s.top();
        }
        s.pop();
    }
    
  
    int top() {
        if(s.empty()) return -1;
        if(s.top() < mini){
            return mini;
        }
        return s.top();
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




/*intuition behind the "2 * ME - Y" that he was talking about 

So we need to find a way to encode the new minimum element with the previous minimum element and then update the minimum element with the new one. After we encode the two mins using a special formula, if later a pop operation comes in which this encoded number is at the top, it means we've to remove the new min from stack and as we stored separately, we can get back the previous min from this encoded number. 

The simplest way you can encode the new min with the previous min is a linear combination of them both, as in, push some "c1 * new_min + c2 * prev_min (where c1 and c2 are some integers). 

But there's a small catch. We need to ensure that our encoded number is less than the new min, because we need to know as to when do we have to remove the new min and retrieve the previous one. The best way to know is to see if the current stack top has a value smaller than the new minimum. It should technically be impossible that an element in stack is smaller than the new minimum, because if it was, then our new minimum would've been that element instead (I hope it's not too confusing lol).

So we need to reach this point: 
c1 * new_min + c2 * prev_min < new_min (so the equation to the LHS is our encoding formula)

If c1 * new_min + c2 * prev_min is our formula for encoding the 2 numbers, what's our decoding formula? As in, when we've to pop this encoded number, how we get the previous minimum? We simply do this: rearrange the equation 

encoded_number = c1 * new_min + c2 * prev_min

to

prev_min = (encoded number - c1 * min) / c2    or    (c1 * min - encoded number) / -c2   

As a good programmer, you need to understand that even if at a large scale it may not matter, but it's better to assign c2 as -1 (For 2nd decoding formula) or 1 (for 1st decoding formula) so that we don't have to do any extra division while decoding back. We'll see whether c2 becomes -1 or 1 based on the encoding formula we generate, and then accordingly the decoding formula will be known.

So now we've to only find what is c1 and create a formula which has c2 = 1 or c2 = -1.

We know that

new_min < prev_min.

We can change new_min to 2 * new_min - new_min:

2 * new_min - new_min < prev_min

Then we rearrange to get:

2 * new_min - prev_min < new_min    (which is the way we wanted our formula to be)

So our c1 = 2 and c2 = -1. And since c2 = -1, our decoding formula will be the 2nd one above.

And that's why we push that (2 * ME - Y) number on stack. I hope this clears up the intuition behind the formula.

If you don't care about division's time complexity, you can generate your own c1 and c2 like this by playing with the values and starting from new_min < prev_min and getting the inequation of that type which I said above


NOTE :- I was told to create maximum element stack in O(1) space, instead of minimum element. I couldn't use the same logic for max, so the interviewer gave me a hint which cleared it out. 

The logic is again similar to minimum element, this time, you need to push such a linear combination which is greater than the new max that comes to the stack, because that's the point which tells that this is where you pushed your new_max.

c1 * new_max + c2 * prev_max > new_max

The simplest values of c1 and c2 we can take is 1.

So in case of max element stack, push new_max + prev_max to stack. While popping, if stack top > new_max, retrieve the prev_max by subtracting new_max from stack top.

Again, logic fails when there are negative numbers, so be careful about that. At the moment I don't know what can be done to deal with negatives.



My simple explanation for the formula:

What do we want to achieve?
We have newMin and prevMin, we want to convert newMin into something like c1*newMin + c2*prevMin, where c1 and c2 are constants
Lest call c1*newMin + c2*prevMin = E

Suppose we converted out newMin to E and pushed to Stack, but how will we recognise it 
For that we need E < newMin

so we two conditions
1) E = c1*newMin + c2*prevMIn
2) E < newMIn

What should be the value of c1 and c2?

My simple intuitive derivation:

we have newMin and prevMin:
newMin < prevMIn 

now adding newMin on both side:
2 * newMIn < prevMin + newMin
2 * newMin - prevMIn < newMin

On LHS we can see some thing similar to E, i.e. c1*newMin + c2*prevMin with c1 = 1 and c2 = -1

Conclusion:

While pushing:
When we get a value, smaller than our currMin, then this val will become out newMin and we will push
2 * newMin - prevMin into the stack.

While popping: 
If we pop a value which is smaller than our minElement means that this is some oldMin.

we know, 2*newMin - prevMin is stored in stack say X
X = 2*newMin - prevMin

We also know our newMIn, so our prevMin can be easily found out by:

prevMin = 2*newMin - X.
*/