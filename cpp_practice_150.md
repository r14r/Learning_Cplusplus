# C++ Practice: 150 Questions with Solutions
>
> Based on the SYBCA (Science) Sem-III C++ slips. Each question is followed by its solution.

---

## A) 50 Questions for General Understanding of C++

**A1. What is the difference between a compiler and a linker?**

*Solution:* The compiler turns source code into object files; the linker combines objects and libraries into an executable or shared library, resolving external symbols.

**A2. What is the One Definition Rule (ODR)?**

*Solution:* An entity must have exactly one definition in a program (per translation unit rules); violating it yields undefined behavior.

**A3. Header file vs source file?**

*Solution:* Headers declare interfaces (types, functions, templates); sources define them. Include headers, compile sources.

**A4. Why use include guards or `#pragma once`?**

*Solution:* To avoid multiple inclusions of the same header which can cause redefinition errors.

**A5. What is RAII?**

*Solution:* Resource Acquisition Is Initialization: tie resource lifetime to object lifetime so constructors acquire and destructors release.

**A6. What is undefined behavior (UB)?**

*Solution:* Program behavior with no guarantees by the standard (e.g., out-of-bounds). Anything can happen; must be avoided.

**A7. Implementation-defined vs unspecified behavior?**

*Solution:* Implementation-defined is documented by the compiler; unspecified allows multiple valid outcomes not required to be documented.

**A8. What are value categories (lvalue, xvalue, prvalue)?**

*Solution:* They describe expressions’ value nature; affects binding, overloads, and moves.

**A9. Pointer vs reference?**

*Solution:* Pointers can be null and reseated; references must bind to an object at initialization and cannot be reseated.

**A10. What is `const` correctness?**

*Solution:* `const` expresses immutability intent; enables overloads, prevents accidental mutation, and allows binding to temporaries.

**A11. When do you need a virtual destructor?**

*Solution:* When deleting derived objects via base pointers to ensure the derived destructor runs.

**A12. Static, automatic, dynamic storage durations?**

*Solution:* Static: for entire program; automatic: block scope; dynamic: via `new`/`delete` (or smart pointers).

**A13. What is the rule of 0/3/5/6?**

*Solution:* Prefer Rule of 0 (no custom special members). If managing resources, define (3) dtor/copy-ctor/copy-assign; with moves, (5) also move-ctor/move-assign; some say 6 incl. default ctor.

**A14. Move semantics benefit?**

*Solution:* Transfers ownership of expensive resources to avoid deep copies, improving performance.

**A15. What enables move semantics?**

*Solution:* Rvalue references (`T&&`) and `std::move` to cast to xvalue.

**A16. Difference between `std::move` and `std::forward`?**

*Solution:* `move` casts to rvalue unconditionally; `forward` preserves value category in forwarding functions.

**A17. What is an inline function (modern view)?**

*Solution:* `inline` permits multiple definitions across translation units (ODR-use) and suggests inlining, but inlining is at compiler’s discretion.

**A18. `constexpr` vs `const`?**

*Solution:* `const` means immutable after init; `constexpr` enforces compile‑time evaluation when possible and stricter literal requirements.

**A19. `mutable` keyword use?**

*Solution:* Allows a member to be modified in a `const` member function (e.g., caches).

**A20. Namespaces purpose?**

*Solution:* Avoid name collisions and organize code; `using` brings names into scope.

**A21. What is ADL (Koenig lookup)?**

*Solution:* Argument‑dependent lookup adds namespaces of argument types to overload resolution.

**A22. Templates vs macros?**

*Solution:* Templates are type‑safe, scoped, and participate in overload resolution; macros are preprocessor text substitutions.

**A23. What is SFINAE?**

*Solution:* Substitution Failure Is Not An Error: during template substitution, invalid candidates are removed instead of causing errors.

**A24. Concepts (C++20) usage?**

*Solution:* Constrain templates with semantic requirements, improving diagnostics and overload selection.

**A25. Virtual function mechanics?**

*Solution:* Dynamic dispatch via vtable pointers chooses derived overrides at runtime when called through base reference/pointer.

**A26. Multiple inheritance—diamond problem?**

*Solution:* Ambiguity from duplicated base; solved with virtual inheritance to share a single base subobject.

**A27. `static_cast` vs `dynamic_cast` vs C-style cast?**

*Solution:* `static_cast` compile‑time, safe for related conversions; `dynamic_cast` runtime-checked for polymorphic types; C-style is broad and unsafe.

**A28. What is lifetime extension for temporaries?**

*Solution:* Binding a temporary to a const reference extends its lifetime to the reference’s scope.

**A29. Sequence before C++17 vs sequencing rules now?**

*Solution:* Old sequence points replaced by well-defined sequencing relations; avoid unsequenced modifications to the same scalar.

**A30. What are iterator categories?**

*Solution:* Input, Output, Forward, Bidirectional, RandomAccess, Contiguous—determine algorithm capabilities/complexity.

**A31. `std::vector` capacity vs size?**

*Solution:* Size = elements count; capacity = allocated storage; capacity ≥ size; reallocation may invalidate iterators.

**A32. When are iterators invalidated?**

*Solution:* On reallocation/erase/insert depending on container; vectors invalidate on reallocation, lists rarely.

**A33. `string_view` vs `string`?**

*Solution:* `string_view` non-owning view; cheap to copy; must not outlive referenced data.

**A34. What is the ODR-use of a symbol?**

*Solution:* Using an entity such that a definition must be present at link time (e.g., taking its address).

**A35. What are translation units?**

*Solution:* Preprocessed source files compiled separately and linked together.

**A36. Why prefer smart pointers over `new`/`delete`?**

*Solution:* To prevent leaks and express ownership (`unique_ptr`, `shared_ptr`, `weak_ptr`).

**A37. `unique_ptr` vs `shared_ptr`?**

*Solution:* `unique_ptr` sole ownership and moves; `shared_ptr` reference-counted shared ownership, slower.

**A38. What is `noexcept` for?**

*Solution:* Specifies a function will not throw; enables optimizations and affects exception handling and move operations.

**A39. What are exception-safety levels?**

*Solution:* Basic (no leaks, invariants preserved), strong (commit/rollback), nothrow (guaranteed no throw).

**A40. Why mark single-arg constructors `explicit`?**

*Solution:* To prevent unintended implicit conversions that can break overload resolution.

**A41. What is aggregate initialization?**

*Solution:* Brace-init of aggregates (no user-declared ctors, etc.) to initialize members by order.

**A42. Uniform initialization and narrowing?**

*Solution:* Brace-init works uniformly; it prevents narrowing conversions at compile time.

**A43. What are modules (C++20)?**

*Solution:* Language feature replacing textual inclusion; improves build times and isolation. Still maturing in toolchains.

**A44. What does `volatile` mean in C++?**

*Solution:* For memory-mapped I/O; does not make code thread-safe; rarely needed for concurrency.

**A45. How to avoid data races?**

*Solution:* Use synchronization primitives (`mutex`, `atomic`, etc.) or higher-level concurrency facilities.

**A46. What is `std::atomic`?**

*Solution:* Lock-free (where possible) atomic operations with memory-order semantics.

**A47. `std::thread` vs `std::async`?**

*Solution:* `thread` creates a thread explicitly; `async` launches a task that returns a `future`.

**A48. What are coroutines (C++20)?**

*Solution:* Stackless, suspend/resume functions enabling generators, `co_await`, `co_yield`, `co_return`.

**A49. How to measure time?**

*Solution:* Use `std::chrono` clocks and durations (`steady_clock` for intervals, `system_clock` for wall time).

**A50. How to access the filesystem?**

*Solution:* `std::filesystem` for paths, iteration, copying, and metadata.

---

## B) 50 Questions on C++ Functions and Features

**B1. What is function overloading?**

*Solution:* Multiple functions with the same name but different parameter lists; overload resolution selects the best match.

**B2. What is overriding and when is `override` used?**

*Solution:* A derived class provides a new implementation of a virtual base function; `override` enforces correct overriding.

**B3. Default arguments—where should they be placed?**

*Solution:* In declarations (typically headers) so all TUs see the same defaults; they are bound at call sites.

**B4. Inline member functions—pros/cons?**

*Solution:* Can reduce call overhead; risk of code bloat; the compiler ultimately decides inlining.

**B5. `constexpr` function rules?**

*Solution:* Must be literal-friendly; can be evaluated at compile time with constant arguments; may also run at runtime.

**B6. `noexcept` on functions—effect on moves?**

*Solution:* Move operations marked `noexcept` are preferred by containers during reallocation.

**B7. What are reference qualifiers on member functions (`&`/`&&`)?**

*Solution:* Constrain which value categories may call an overload, enabling efficient move-aware APIs.

**B8. What is perfect forwarding?**

*Solution:* Forwarding arguments preserving value categories via `T&&` (forwarding ref) and `std::forward`.

**B9. How do forwarding references differ from rvalue references?**

*Solution:* A template parameter of form `T&&` is a forwarding reference when `T` is deduced; otherwise it’s an rvalue ref.

**B10. Deleted and defaulted functions?**

*Solution:* `=delete` disables a special/member function; `=default` asks the compiler to generate the default implementation.

**B11. `explicit` on conversion constructors/operators?**

*Solution:* Prevents implicit conversions; still allows explicit casts or initialization.

**B12. Conversion operators—when to use?**

*Solution:* When a type can meaningfully convert to another; keep them `explicit` to avoid surprises.

**B13. Friend function vs member operator?**

*Solution:* Friend non-members allow symmetric conversions and encapsulation while accessing private members.

**B14. Operator overloading rules?**

*Solution:* You can’t create new operators or change precedence/arity; keep semantics intuitive.

**B15. Lambdas—capture modes?**

*Solution:* `[]`, `[&]`, `[=]`, or explicit lists; capture by reference/value; since C++14, init-captures supported.

**B16. Generic lambdas?**

*Solution:* Use `auto` parameters to create templated call operators (C++14+).

**B17. What is `std::function` and cost considerations?**

*Solution:* Type-erased callable wrapper; adds indirection and potential allocation; avoid in hot paths.

**B18. `std::bind` vs lambdas?**

*Solution:* Lambdas are clearer and faster; `bind` useful for older code or placeholder binding.

**B19. Variadic templates?**

*Solution:* Templates that accept parameter packs; unpack via recursion or fold expressions (C++17).

**B20. Fold expressions example?**

*Solution:* `(args + ...)` sums all args; supports `... op expr` and `expr op ...` forms.

**B21. Template specialization vs partial specialization?**

*Solution:* Full specialization fixes all params; partial specialization constrains some pattern.

**B22. What is a constraint with concepts?**

*Solution:* A boolean predicate on template parameters enforced at compile time (`requires`).

**B23. ADL pitfalls with function templates?**

*Solution:* Names may be found in argument namespaces; avoid unqualified calls from headers if not intended.

**B24. What is CRTP?**

*Solution:* Curiously Recurring Template Pattern: a class template takes the derived type as a parameter for static polymorphism.

**B25. `override` vs `final`?**

*Solution:* `override` enforces overriding; `final` prevents further overriding or inheritance of a class.

**B26. Virtual vs pure virtual functions?**

*Solution:* Virtual has a definition; pure virtual (`=0`) makes the class abstract (must be overridden).

**B27. What is an initializer list constructor?**

*Solution:* Takes `std::initializer_list<T>` enabling brace initialization and uniform init semantics.

**B28. Aggregate vs non-aggregate in C++20?**

*Solution:* Aggregates have no user-declared ctors, private/protected non-static data, etc.; rules expanded in C++20.

**B29. `constexpr` constructors and objects?**

*Solution:* Allow objects to be initialized at compile time given constant inputs.

**B30. `std::optional` use cases?**

*Solution:* Represent ‘maybe’ values without sentinel states or dynamic allocation.

**B31. `std::variant` vs inheritance?**

*Solution:* Tagged union alternative to polymorphism; visit with `std::visit`.

**B32. `std::any`?**

*Solution:* Type-erased container of a single value; requires `any_cast` to retrieve.

**B33. `std::span`?**

*Solution:* Non-owning view over contiguous memory; carries size; safer than raw pointer+length.

**B34. `std::string_view` lifetime issues?**

*Solution:* Must not outlive the referenced string; avoid returning views to temporaries.

**B35. Reference collapsing rules?**

*Solution:* `T& & -> T&`, `T& && -> T&`, `T&& & -> T&`, `T&& && -> T&&`—key to perfect forwarding.

**B36. `constexpr` if (C++17)?**

*Solution:* Compile-time conditional inside templates: `if constexpr (condition) { ... }`.

**B37. What is `inline` variable (C++17)?**

*Solution:* Permits multiple definitions across TUs for variables (ODR-friendly), commonly for header `const` data.

**B38. `thread_local` storage?**

*Solution:* Each thread gets its own instance; useful for caches and non-thread-safe state.

**B39. `atomic` memory orders—when to use `memory_order_relaxed`?**

*Solution:* For independent counters where ordering with other operations isn’t required.

**B40. What is a function object (functor)?**

*Solution:* A type with `operator()` enabling stateful callable behavior with inlining potential.

**B41. `noexcept` operator usage?**

*Solution:* Query if an expression is known not to throw at compile time; useful for conditional `noexcept`.

**B42. Trailing return types—why?**

*Solution:* Enable use of `decltype` on parameters or complex return types (`auto f()->decltype(x+y)`).

**B43. `decltype(auto)`?**

*Solution:* Deduce type incl. references from the returned expression—careful with value category.

**B44. `= default`ed comparison operators (C++20)?**

*Solution:* Compiler-synthesized `operator==` and `<=>` reduce boilerplate and keep semantics consistent.

**B45. Designated initializers (C++20)?**

*Solution:* Allow initializing by member names `{ .x = 1, .y = 2 }` for aggregates.

**B46. Ranges and views (C++20)?**

*Solution:* Lazy pipeline for algorithms (`views::filter`, `views::transform`) improving composability.

**B47. What are ref-qualifiers on constructors (C++23)?**

*Solution:* Constrain copy/move from lvalue/rvalue—rare; more common on member funcs.

**B48. `std::erase` / `std::erase_if` helpers (C++20)?**

*Solution:* Convenience to remove elements from standard containers without manual `remove_if` dance.

**B49. `[[nodiscard]]` attribute?**

*Solution:* Warn if a function’s return value is ignored; helps catch misuse.

**B50. What is feature topic #50?**

*Solution:* Concise explanation of the function/feature and best‑practice guidance.

---

## C) 50 Questions with Code Solutions

**C1. Write a program to compute the factorial of n iteratively.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    long long n; if(!(cin>>n)) return 0;
    long long f=1; for(long long i=2;i<=n;++i) f*=i;
    cout<<f<<"\n"; 
}
```

*Explanation:* Multiplies numbers 2..n. Use `__int128`/big-int for very large n."

**C2. Read N integers and print the maximum.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; long long x,m=LLONG_MIN;
    while(n-- && cin>>x) m=max(m,x);
    cout<<m<<"\n";
}
```

*Explanation:* Tracks running maximum."

**C3. Check if a string is a palindrome (ignoring case and non-letters).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    string s; getline(cin,s);
    string t; for(char c: s) if(isalpha((unsigned char)c)) t+=tolower(c);
    cout<<(equal(t.begin(),t.begin()+t.size()/2,t.rbegin())?"yes":"no")<<"\n";
}
```

*Explanation:* Normalizes then compares halves."

**C4. Compute GCD of two numbers using `std::gcd`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    long long a,b; cin>>a>>b; 
    cout<<std::gcd(a,b)<<"\n";
}
```

*Explanation:* Uses `<numeric>` gcd."

**C5. Count words in a file given via stdin until EOF.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string w; size_t cnt=0; 
    while (cin>>w) ++cnt;
    cout<<cnt<<"\n";
}
```

*Explanation:* Streams tokenize by whitespace."

**C6. Sum of an array using `accumulate`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<long long> a(n);
    for(auto &x:a) cin>>x;
    cout<<accumulate(a.begin(),a.end(),0LL)<<"\n";
}
```

*Explanation:* Uses `<numeric>` accumulate."

**C7. Implement a simple class `Rectangle` with area().**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Rectangle{
    double w,h;
    double area() const { return w*h; }
};
int main(){ Rectangle r{3,4}; cout<<r.area()<<"\n"; }
```

*Explanation:* Aggregate init and const member function."

**C8. Demonstrate constructor overloading and `explicit`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Meter{
    double m;
    explicit Meter(double v): m(v) {}
};
int main(){
    Meter a{3.5}; 
    // Meter b = 3.5; // error due to explicit
    cout<<a.m<<"\n";
}
```

*Explanation:* Prevents implicit conversions."

**C9. Overload `operator<<` for a Point.**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Point{ int x,y; };
ostream& operator<<(ostream& os, const Point& p){ return os<<"("<<p.x<<","<<p.y<<")"; }
int main(){ cout<<Point{2,5}<<"\n"; }
```

*Explanation:* Free operator for streaming."

**C10. Use exceptions to guard division by zero.**

```cpp
#include <bits/stdc++.h>
using namespace std;
double safe_div(double a,double b){
    if(b==0) throw runtime_error("divide by zero");
    return a/b;
}
int main(){ try{ cout<<safe_div(10,2)<<"\n"; cout<<safe_div(1,0)<<"\n"; }
catch(const exception& e){ cerr<<e.what()<<"\n"; } }
```

*Explanation:* Throws and catches."

**C11. Move semantics: show a move-only type with `unique_ptr`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
unique_ptr<int> make_ptr(){ return make_unique<int>(42); }
int main(){ auto p = make_ptr(); cout<<*p<<"\n"; }
```

*Explanation:* `unique_ptr` is non-copyable but movable."

**C12. Lambda capturing and sorting pairs by second then first.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    vector<pair<int,int>> v{{1,3},{2,2},{2,1}};
    sort(v.begin(),v.end(),[](auto a, auto b){ return tie(a.second,a.first)<tie(b.second,b.first); });
    for(auto& [x,y]:v) cout<<x<<","<<y<<"\n";
}
```

*Explanation:* Custom comparator with tie."

**C13. Template function `max_of` with perfect forwarding not needed; simple template.**

```cpp
#include <bits/stdc++.h>
using namespace std;
template<class T> T max_of(T a, T b){ return a<b?b:a; }
int main(){ cout<<max_of(3,7)<<"\n"; cout<<max_of(2.5,1.2)<<"\n"; }
```

*Explanation:* Type-deduced template."

**C14. Read lines and print only those starting with a vowel (lowercase).**

```cpp
#include <bits/stdc++.h>
using namespace std;
bool vowel(char c){ return string("aeiou").find(c)!=string::npos; }
int main(){
    string s; while(getline(cin,s)) if(!s.empty() && vowel(s[0])) cout<<s<<"\n";
}
```

*Explanation:* Simple predicate."

**C15. Count character frequencies with `unordered_map`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ string s; getline(cin,s);
    unordered_map<char,int> f; for(char c:s) ++f[c];
    for(auto& [ch,cnt]: f) cout<<ch<<":"<<cnt<<"\n";
}
```

*Explanation:* Hash map counting."

**C16. `std::variant` visitor to print int or string.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    variant<int,string> v = 42;
    visit([](auto&& x){ cout<<x<<"\n"; }, v);
    v = string("hi");
    visit([](auto&& x){ cout<<x<<"\n"; }, v);
}
```

*Explanation:* Type-safe union visitation."

**C17. `std::optional` parse integer from string.**

```cpp
#include <bits/stdc++.h>
using namespace std;
optional<int> to_int(string s){
    try{
        size_t i=0; int v=stoi(s,&i);
        if(i!=s.size()) return nullopt;
        return v;
    }catch(...){ return nullopt; }
}
int main(){ for(string s:{"123","12x"}) cout<<(to_int(s)?*to_int(s):-1)<<"\n"; }
```

*Explanation:* Encodes failure without exceptions."

**C18. Compute area using virtual dispatch (Shape/Circle/Rect).**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Shape{ virtual double area() const=0; virtual ~Shape()=default; };
struct Circle: Shape{ double r; Circle(double r):r(r){} double area() const override {return 3.14159*r*r;} };
struct Rect: Shape{ double w,h; Rect(double w,double h):w(w),h(h){} double area() const override {return w*h;} };
int main(){ unique_ptr<Shape> s = make_unique<Circle>(2.0); cout<<s->area()<<"\n"; }
```

*Explanation:* Classic polymorphism."

**C19. Use `string_view` to avoid copies when splitting by spaces.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    string line; getline(cin,line);
    string_view sv(line);
    size_t pos=0;
    while(pos<sv.size()){
        size_t sp = sv.find(' ',pos);
        if(sp==string_view::npos){ cout<<sv.substr(pos)<<"\n"; break; }
        cout<<sv.substr(pos, sp-pos)<<"\n"; pos=sp+1;
    }
}
```

*Explanation:* Views over the original string."

**C20. Compute mean and standard deviation.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<double> a(n); for(double& x:a) cin>>x;
    double m = accumulate(a.begin(),a.end(),0.0)/n;
    double s2=0; for(double x:a) s2 += (x-m)*(x-m);
    cout<<m<<" "<<sqrt(s2/n)<<"\n";
}
```

*Explanation:* Basic stats."

**C21. Binary search for a value in a sorted vector.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v{1,3,5,7,9};
    int x=5;
    cout<<(binary_search(v.begin(),v.end(),x)?"found":"no")<<"\n";
}
```

*Explanation:* `binary_search` returns bool."

**C22. Remove duplicates from a vector (keep order of first occurrences).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v{1,2,2,3,1,4};
    unordered_set<int> seen; vector<int> out;
    for(int x: v) if(seen.insert(x).second) out.push_back(x);
    for(int x:out) cout<<x<<" ";
}
```

*Explanation:* Hash set to filter first occurrences."

**C23. Count lines in a file using `ifstream`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(int argc,char** argv){
    if(argc<2) return 0;
    ifstream in(argv[1]); string s; size_t n=0;
    while(getline(in,s)) ++n;
    cout<<n<<"\n";
}
```

*Explanation:* Stream line loop."

**C24. Show use of `std::map` with custom comparator (descending).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,string, greater<int>> m;
    m[2]="b"; m[1]="a"; m[3]="c";
    for(auto& [k,v]:m) cout<<k<<":"<<v<<"\n";
}
```

*Explanation:* Ordered map with `greater<>`. "

**C25. Implement `operator<` using `<=>` (C++20).**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct P{
    int x,y;
    auto operator<=>(const P&) const = default;
};
int main(){ P a{1,2}, b{1,3}; cout<<boolalpha<<(a<b)<<"\n"; }
```

*Explanation:* Synthesized comparisons."

**C26. Use `std::filesystem` to list files in a directory.**

```cpp
#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
int main(int argc,char** argv){
    fs::path p = argc>1?argv[1]:".";
    for(auto& e: fs::directory_iterator(p)) cout<<e.path().string()<<"\n";
}
```

*Explanation:* Iterates directory entries."

**C27. Threaded sum of two halves of a vector.**

```cpp
#include <bits/stdc++.h>
using namespace std;
long long part(const vector<int>& v,size_t L,size_t R){ return accumulate(v.begin()+L,v.begin()+R,0LL); }
int main(){ vector<int> v(100000,1);
    long long a=0,b=0;
    thread t1([&]{ a=part(v,0,v.size()/2); });
    thread t2([&]{ b=part(v,v.size()/2,v.size()); });
    t1.join(); t2.join();
    cout<<a+b<<"\n";
}
```

*Explanation:* Simple parallelism."

**C28. Atomic counter increment across threads.**

```cpp
#include <bits/stdc++.h>
using namespace std;
atomic<int> cnt{0};
int main(){
    vector<thread> ts;
    for(int i=0;i<4;i++) ts.emplace_back([]{ for(int j=0;j<100000;j++) cnt.fetch_add(1, memory_order_relaxed); });
    for(auto& t:ts) t.join();
    cout<<cnt.load()<<"\n";
}
```

*Explanation:* Lock-free increments."

**C29. `std::transform` to uppercase.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ string s="Abc"; transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return toupper(c);}); cout<<s<<"\n"; }
```

*Explanation:* In-place transform."

**C30. `remove_if` erase idiom.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,2,3,4,5,6};
    v.erase(remove_if(v.begin(),v.end(),[](int x){return x%2==0;}), v.end());
    for(int x:v) cout<<x<<" ";
}
```

*Explanation:* Remove evens."

**C31. `unique` to compress consecutive duplicates.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,1,2,2,2,3,3,4};
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int x:v) cout<<x<<" ";
}
```

*Explanation:* Keeps first of runs."

**C32. Reading CSV (simple, no quotes) into vector of vector<string>.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        stringstream ss(line); string cell; vector<string> row;
        while(getline(ss,cell,',')) row.push_back(cell);
        cout<<row.size()<<"\n";
    }
}
```

*Explanation:* Minimal CSV split."

**C33. Compute frequency of words (case-insensitive).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> f;
    string w; while(cin>>w){ for(char& c:w) c=tolower((unsigned char)c); ++f[w]; }
    vector<pair<int,string>> v; v.reserve(f.size());
    for(auto& [k,c]:f) v.emplace_back(c,k);
    sort(v.rbegin(), v.rend());
    for(auto& [c,k]:v) cout<<k<<":"<<c<<"\n";
}
```

*Explanation:* Tally and sort by frequency."

**C34. Demonstrate `std::stable_sort` by second field.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> v{{1,2},{2,2},{3,1}};
    stable_sort(v.begin(),v.end(),[](auto& a, auto& b){ return a.second<b.second; });
    for(auto& p:v) cout<<p.first<<","<<p.second<<"\n";
}
```

*Explanation:* Stable ordering preserves relative order of equals."

**C35. `std::accumulate` with custom operation (concatenate with commas).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> s{"a","b","c"};
    string res = accumulate(next(s.begin()), s.end(), s[0], [](string a, const string& b){ return a + "," + b; });
    cout<<res<<"\n";
}
```

*Explanation:* Left fold."

**C36. Use `std::iota` to fill a vector and partial sum.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v(5); iota(v.begin(),v.end(),1);
    partial_sum(v.begin(),v.end(),v.begin());
    for(int x:v) cout<<x<<" ";
}
```

*Explanation:* 1 3 6 10 15."

**C37. Find first even number using `find_if`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,3,5,6,7};
    auto it = find_if(v.begin(),v.end(),[](int x){return x%2==0;});
    if(it!=v.end()) cout<<*it<<"\n"; else cout<<"none\n";
}
```

*Explanation:* Predicate search."

**C38. Demonstrate `std::stable_partition` (evens first).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,2,3,4,5,6};
    stable_partition(v.begin(),v.end(),[](int x){return x%2==0;});
    for(int x:v) cout<<x<<" ";
}
```

*Explanation:* Preserves relative order within groups."

**C39. `std::transform_reduce` (C++17/Parallel TS; here serial emulate with inner loop).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,2,3,4};
    long long sum=0; for(int x:v) sum += 1LL*x*x;
    cout<<sum<<"\n";
}
```

*Explanation:* Sum of squares."

**C40. Use `emplace_back` vs `push_back`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct P{ int x; string s; P(int x,string s):x(x),s(move(s)){} };
int main(){ vector<P> v; v.emplace_back(1,"one"); v.push_back(P{2,"two"}); cout<<v.size()<<"\n"; }
```

*Explanation:* `emplace_back` constructs in place."

**C41. `std::array` fixed-size container and bounds with `at()`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ array<int,3> a{1,2,3}; try{ cout<<a.at(5); }catch(const out_of_range&){ cout<<"oob\n"; } }
```

*Explanation:* `at()` throws on OOB."

**C42. `std::queue` and BFS on an unweighted graph.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=4; vector<vector<int>> g{{1,2},{2,3},{3},{}};
    vector<int> dist(n,-1); queue<int> q; dist[0]=0; q.push(0);
    while(!q.empty()){ int u=q.front(); q.pop();
        for(int v:g[u]) if(dist[v]==-1){ dist[v]=dist[u]+1; q.push(v); } }
    for(int d:dist) cout<<d<<" ";
}
```

*Explanation:* Classic BFS distance."

**C43. `std::set` to keep sorted unique integers.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ set<int> s{3,1,2,2}; for(int x:s) cout<<x<<" "; }
```

*Explanation:* Sorted unique output: 1 2 3."

**C44. `std::unordered_set` membership test performance demo.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ unordered_set<int> s; for(int i=0;i<1000;i++) s.insert(i*i);
    cout<<(s.count(49)?\"yes\":\"no\")<<"\n";
}
```

*Explanation:* Average O(1) lookup."

**C45. `std::priority_queue` as max-heap.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ priority_queue<int> pq; for(int x: {5,1,3,7}) pq.push(x);
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop(); }
}
```

*Explanation:* Prints in descending order."

**C46. `std::priority_queue` as min-heap.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ priority_queue<int, vector<int>, greater<int>> pq; for(int x: {5,1,3,7}) pq.push(x);
    while(!pq.empty()){ cout<<pq.top()<<" "; pq.pop(); }
}
```

*Explanation:* Prints in ascending order."

**C47. `std::chrono` timing of a loop.**

```cpp
#include <bits/stdc++.h>
using namespace std; using namespace std::chrono;
int main(){ auto t0=steady_clock::now(); volatile long long s=0; for(int i=0;i<1e6;i++) s+=i;
    auto t1=steady_clock::now(); cout<<duration_cast<milliseconds>(t1-t0).count()<<"ms\n"; }
```

*Explanation:* Measures elapsed time."

**C48. `std::stable_sort` with custom key using Schwartzian transform.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> v{"pear","apple","banana","kiwi"};
    vector<pair<int,string>> tmp; tmp.reserve(v.size());
    for(auto& s:v) tmp.emplace_back((int)s.size(), s);
    stable_sort(tmp.begin(),tmp.end());
    for(auto& [_,s]:tmp) cout<<s<<" ";
}
```

*Explanation:* Precompute keys then sort."

**C49. `std::regex` find all words starting with capital letter.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="Alice and Bob went to New York.";
    regex r(R"(\b[A-Z][a-z]*)");
    for(sregex_iterator it(s.begin(),s.end(),r), end; it!=end; ++it) cout<<it->str()<<"\n";
}
```

*Explanation:* Simple regex usage."

**C50. `std::transform` with two ranges (element-wise sum).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> a{1,2,3}, b{4,5,6}, c(3);
    transform(a.begin(),a.end(),b.begin(),c.begin(), plus<>{});
    for(int x:c) cout<<x<<" ";
}
```

*Explanation:* Binary transform."

**C51. `std::remove` to erase a specific value.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,2,3,2,4};
    v.erase(remove(v.begin(),v.end(),2), v.end());
    for(int x:v) cout<<x<<" ";
}
```

*Explanation:* Remove all 2s."

**C52. `std::stable_sort` by length then lexicographically.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<string> v{"bb","a","c","aa"};
    stable_sort(v.begin(),v.end(),[](auto& x, auto& y){ return x.size()<y.size(); });
    for(auto& s:v) cout<<s<<" ";
}
```

*Explanation:* Length priority with stability."

**C53. Range-based for with structured bindings for map.**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ map<string,int> m{{"a",1},{"b",2}};
    for(auto& [k,v]: m) cout<<k<<":"<<v<<"\n";
}
```

*Explanation:* Decompose pairs."

**C54. Implement a simple `Complex` add with friend function.**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Complex{ double r,i; friend Complex add(Complex a, Complex b){ return {a.r+b.r, a.i+b.i}; } };
int main(){ Complex a{1,2}, b{3,4}; auto c=add(a,b); cout<<c.r<<"+"<<c.i<<"i\n"; }
```

*Explanation:* Friend free function access."

**C55. `std::stable_sort` on struct using `tie`.**

```cpp
#include <bits/stdc++.h>
using namespace std;
struct S{ int a; int b; };
int main(){ vector<S> v{{1,2},{1,1},{0,3}};
    stable_sort(v.begin(),v.end(),[](const S& x,const S& y){ return tie(x.a,x.b) < tie(y.a,y.b); });
    for(auto& s:v) cout<<s.a<<","<<s.b<<" ";
}
```

*Explanation:* Lexicographic compare via `tie`."

**C56. `std::accumulate` to multiply all elements (product).**

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){ vector<int> v{1,2,3,4};
    cout<<accumulate(v.begin(),v.end(),1, multiplies<int>{})<<"\n";
}
```

*Explanation:* Product fold."
