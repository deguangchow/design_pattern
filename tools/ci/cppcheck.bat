ECHO ======== Check CppCheck Start ========

cppcheck --enable=warning,performance --inconclusive design_pattern test > cppcheck.log

ECHO ======== Check CppCheck Result ========