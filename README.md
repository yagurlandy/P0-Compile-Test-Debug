# P0 - Compile, Test, Debug

* Name: Erandy Lopez-Martinez
* Email: [andylopezmartine@u.boisestate.edu](mailto:andylopezmartine@u.boisestate.edu)
* Class: CS 425-001

## Known Bugs or Issues

I did not find any issues with the final code. It compiles without warnings in GitHub Codespaces, all of the unit tests pass, `lab.c` has 100% code coverage, and AddressSanitizer does not report any memory issues.

I was not able to test it on Onyx because I could not connect to the Boise State VPN on multiple devices. I also tried connecting directly through SSH while off campus, but the connection timed out. This appears to be an access issue rather than an issue with the code.

## Experience

This project helped me better understand the difference between declaring a function in a header file and actually implementing it in a source file. It also helped me understand how Unity tests compare the expected and actual results. One of my biggest takeaways was that passing all of the tests does not automatically mean that a program does not have memory problems.

The crash and memory leak portions were especially helpful. When I first ran the leak check, it reported the null-pointer crash instead of the memory leak because the program crashed before it could finish. Once I removed the crash, LeakSanitizer was able to show me the exact allocation and line that caused the leak. Using the debugger and breakpoints also helped me see the values change each time the tests called `wrong_sum`.

## Analysis

The debug and release builds behaved differently when I dereferenced a null pointer. The debug build performed the invalid read, and AddressSanitizer showed me where the crash occurred. The release build initially completed normally because the compiler optimized out the unused read. Once I marked the pointer as `volatile`, the compiler could no longer remove that read, so the release build crashed too.

LeakSanitizer reported a 32-byte leak from `main.c`. It also reported three separate four-byte leaks from `wrong_sum`, for a total of 12 bytes, because my test called that function three times. After I removed the intentional crash and memory leaks, both sanitizer checks completed without reporting any memory problems.