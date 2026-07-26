#include "ballistics.hpp"

int main()
{
  Input input{};

  // Reading_Input_file(input);

  if (!Reading_Input_file(input)) {
    return 1;
  };

  ballistics_logic(input);
  return 0;
}
