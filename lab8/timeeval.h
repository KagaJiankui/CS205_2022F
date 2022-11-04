#include <chrono>

#define TIME_START start = std::chrono::steady_clock::now();
#define TIME_END(NAME)                                                                   \
  end      = std::chrono::steady_clock::now();                                           \
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); \
  cout << (NAME) << ": result=" << result << ", duration = " << duration << "ms" << endl;