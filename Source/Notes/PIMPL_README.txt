Goal: reduce header includes & build times

class AccountImpl: Foward Decl - allows compiler to build the object, but code cannot create solid instance of it, access members/functions.
Can have a poiter to it and not include its header.

class Account header:
unique_ptr to the impl, makes class non-copyable but optionally moveable. Free memory management of impl class.
Impl classes - must define destructor
Has a private reference to AccountImpl & is basically an interface - just exposes same public memebers

class Account cpp:
Includes header for Impl
Just calls the public impl methods 1:1
Only this class builds when private impl changes
