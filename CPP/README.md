# 💻 My C++ Labs ft. Lappy (love of my life) - Semester 3 DSA Lab

> *Where segmentation faults taught me more than any textbook ever could*

Remember staring at red highlighted code lines? The thrill of finally getting bubble sort to work? Yes, this is that collection. Welcome to my Semester 3 Data Structures nostalgia trip! 

---

## 📂 What's Inside (My Organized Chaos)

```
CPP/
├── Sorting/          # Where I learned patience (and nested loops)
├── Stack/            # LIFO became my life philosophy
├── Queue/            # Standing in the mess queue, coding queues
├── Searching/        # Find the bug, find the element, find yourself
└── Memory/           # new, delete, segfault, repeat
```

---

## 🚀 Running These Bad Boysssss

### The "Please Just Work" Method
```bash
g++ program_name.cpp -o program_name
./program_name
```

### When You're Feeling Confident
```bash
g++ -O2 program_name.cpp -o program_name
# Optimization flags! Look at me being all professional
```

### The "Eyes are pAiNiNg" Debug Mode
```bash
g++ -Wall -Wextra program_name.cpp -o program_name
# Show me ALL the warnings. I can take it.
```

---

## 📚 The Programs

### 🔄 Sorting/ - *The Nested Loop Saga*

#### 1. **bubble_sort.cpp** - My First Love
- Sorts student records by name or CGPA
- **Complexity:** O(n²) - Yes, it's slow, but it's *my* slow
- **Memory:** O(1) - At least it's space-efficient!
- **Real talk:** This was the first algorithm I understood completely. The bubble analogy finally clicked!

#### 2. **selection_sort.cpp** - The Minimalist
- Find minimum, swap, repeat. Simple life.
- **Complexity:** O(n²) - Same time, fewer swaps though!
- **Best moment:** When I realized it does less swapping than bubble sort and felt like a genius

#### 3. **insertion_sort.cpp** - The Underdog
- **Complexity:** O(n²) worst case, but O(n) when almost sorted!
- **Pro tip:** Use this when your TA gives you "almost sorted" test cases
- **Memory:** Still sorting cards in my head like this algorithm taught me

#### 4. **heap_sort.cpp** - The Intimidating One
- **Complexity:** O(n log n) guaranteed - Finally, sub-quadratic!
- **Space:** O(1) - In-place sorting like a bossssss
- **Confession:** Took me 6 tries to understand heapify. The binary tree visualization!!!!

#### 5. **merge_sort.cpp** - The Divide & Conquer Hero
- Sorts delivery times (because why not make it practical?)
- **Complexity:** O(n log n) - Reliable like me ;)
- **Space:** O(n) - Needs extra space but worth it

---

### 📚 Stack/ - *LIFO or Die Trying*

#### 1. **infix_to_postfix.cpp** - The Expression Wizard
- Converts `(a+b)*c` to `ab+c*`
- **Implementation:** Linked list stack (because we're fancy)
- **Time:** O(n) - One pass, no stress
- **Eureka moment:** When I realized calculators use this internally 🤯

#### 2. **infix_to_prefix.cpp** - The Mind Bender
- Same thing but backwards (literally)
- **Algorithm:** Reverse → Convert → Reverse again
- **Brain cells lost:** Too many to count
- **Brain cells gained:** Understanding that sometimes you got to go reverse to move forward

---

### 🎫 Queue/ - *First In, First Out (FIFO sounds so cutteeee!)*

#### 1. **circular_queue.cpp** - The Space Saver
- Array-based circular queue implementation
- **Why circular?** Because wasting array space is lame
- **Operations:** Enqueue, Dequeue, Display
- **Proudest moment:** Getting the wraparound logic right on the first try.

---

### 🔍 Searching/ - *Hide and Seek, Algorithm Edition*

#### 1. **linear_search.cpp** - The Straightforward Friend
- Searches for student ID sequentially
- **Time:** O(n) - Simple but honest work
- **Space:** O(1)
- **Vibe:** "I'll check every single one, no problem"

#### 2. **binary_search.cpp** - The Smart Cookie
- **Time:** O(log n) - SO much faster
- **Catch:** Array must be sorted (there's always a catch)
- **Favorite analogy:** Like finding a word in the dictionary. Nobody actually starts from 'A'!

---

### 🧠Memory/ - *With Great Power Comes Great Segfaults*

#### 1. **dynamic_allocation.cpp** - Growing Up with `new` and `delete`
- Learning to manage memory like a responsible adult
- **Lesson learned:** Every `new` needs a `delete` (unlike borrowed pens that never come back)

#### 2. **realloc_expansion.cpp** - The Array That Wouldn't Quit
- Dynamic array resizing with `realloc()`
- **Use case:** When you don't know how much data is coming
- **Real-world parallel:** Like my code directory that keeps growing

---

## What You Need

- **Compiler:** g++ (C++11 or later)
  - If you're still using Turbo C++, we are not going to talk.
- **OS:** Linux (lab machines), macOS, Windows (MinGW/Cygwin)
- **Patience:** Infinite

---

## 🐛 War Stories (Common Issues I Definitely Never Had)

### "undefined reference to 'main'"
**Translation:** You forgot the main() function, genius  
**Solution:** Add `int main()` - it's not optional

### Memory Leaks Everywhere
**The crime:** Using `new` without `delete`  
**The punishment:** Slowly eating up all your RAM  
**The fix:** 
```cpp
int* arr = new int[10];  // Allocate
// ... use it ...
delete[] arr;             // FREE IT
```

### Segmentation Fault (Core Dumped)
**Common causes:**
- Array out of bounds (check those indices!)
- Null pointer dereference (check before you wreck)
- Using deleted memory (zombie pointers are bad, mkay?)

**Pro tip:** Add lots of `cout` statements. Yes, I know about debuggers. No, I don't always use them.

---

## How I Actually Learned This Stuff

### Week 1-2: The Sorting Marathon
1. Started with bubble sort - felt invincible
2. Tried selection sort - still feeling good
3. Hit insertion sort - confidence slightly shaken
4. Heap sort appeared - 🙏🏻
5. Finally understood merge sort - 💅🏻

### Week 3-4: Stack Overflow (Not the Website)
1. Built a stack from scratch
2. Learned about LIFO (LIFO also sounds cuteeee)
3. Converted infix to postfix until I could do it in my sleep
4. Still dream about operator precedence sometimes

### Week 5-6: Queue Justice
1. Made a regular queue
2. Realized space was wasted
3. Discovered circular queues
4. Mind = blown 🤯

### Week 7-8: The Great Search
1. Linear search - simple, honest, slow
2. Binary search - fast, elegant, requires sorted data
3. Learned that sometimes preparation (sorting) is worth it

### Week 9-10: Memory Management
1. Met `new` and `delete`
2. Met segmentation faults
3. Became best friends with Valgrind
4. Now check for memory leaks in my sleep

---

## 💡 Wisdom Gained (wished someone sat beside me and told me these things)

### Code Truths
- **Always initialize your pointers to NULL/nullptr**  
  Future you will thank present you
  
- **Test edge cases**  
  Empty arrays, single elements, negative numbers - test them ALL
  
- **Comment your code**  
  "I'll remember what this does" - Narrator: They did not remember
  
- **One bug at a time**  
  Don't try to fix everything at once. That way lies madness.

### Lab Life Lessons
- Save frequently (Ctrl+S is muscle memory now)
- Test with small inputs first
- That one friend who finishes early? They're lying or they're a wizard

---

## Key Concepts I Actually Understand Now

✅ **Memory Management** - new, delete, and why malloc is kinda scary  
✅ **Pointers** - Not scary anymore! (Okay, still a little scary)  
✅ **Structures** - Because objects are for next semester  
✅ **Recursion** - A function that calls itself
✅ **Time Complexity** - yes O(n²)   
✅ **Space Complexity** - Memory isn't free. RAM is expensive

---

## 🌟 Personal Bests

- ✨ Got merge sort working without looking at the textbook
- 🎯 Debugged a segfault in under 10 minutes (personal record!)
- 🏆 Explained circular queues to three classmates and it made sense
- 💪 Wrote binary search from memory during the practical exam
- 🎉 Finally understood Big O notation (took long enough)

---

## 📝 Notes to Self

```
TODO for future me:
[ ] Learn about move semantics (C++11 thing)
[ ] Understand why everyone uses vectors instead of arrays
[ ] Figure out what those fancy STL algorithms do
[ ] Maybe learn about smart pointers?
[ ] Stop using 'using namespace std' everywhere
```

---

## 🙏 Acknowledgments

- **Lappy**
- **VS**
- **GOD**

---

## 🎬 Final Thoughts

These programs aren't perfect. Some have inefficiencies. Some could be better documented. But they represent hours of learning, debugging, cursing, and finally that sweet, sweet moment when the program compiles AND runs correctly.

If you're reading this and struggling with DSA, you're not alone. We've all been there, staring at a segfault. Keep going. It gets better (and then you move to Semester 4 and it gets hard again, but that's future you's problem).

**Happy Coding! May your pointers always point to valid memory!**

---

*Made with 🧠&🧡*

*P.S. - If you find a bug, no you didn't silll......wished someone sat beside me and told me these things*
