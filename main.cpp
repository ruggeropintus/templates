//####################################################//
//##### INCLUDES #####################################//
//####################################################//

#include <iostream>
#include <unistd.h> // For getopt

//####################################################//
//##### DEFINES ######################################//
//####################################################//

//####################################################//
//##### TYPEDEFS #####################################//
//####################################################//

//####################################################//
//##### ARGUMENTS ####################################//
//####################################################//

static bool argHelp = false;
static bool argDebug = false;

static void show_usage(int /*argc*/, char **argv) {
  std::cout << "Usage:" << std::endl
            << argv[0] << " [options]" << std::endl
            << "General options:\n"
            << "  -h                   : display help on\n"
            << "  -D                   : debug mode on\n"
            << "\n\n";
}

static int parse_options(int argc, char *argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "hD")) != -1) {
    switch (opt) {
    case 'h': {
      argHelp = true;
      break;
    }
    case 'D': {
      argDebug = true;
      break;
    }
    default:
      std::cerr << "Unknown option: -" << (char)opt << std::endl;
      return 1;
    }
  }

  if (optind + 1 < argc) {
    std::cerr << "\033[0;31m[EE] ERROR - optind vs argc: " << optind << " - "
              << argc << "\033[0m" << std::endl;
    std::cerr << "\033[0;31m[EE] ERROR - Too many input filenames.\033[0m"
              << std::endl;
    return 1;
  }

  return 0;
}

//####################################################//
//##### GLOBAL VARIABLES #############################//
//####################################################//

//####################################################//
//##### DECLARATIONS #################################//
//####################################################//

bool checkInput();

//####################################################//
//##### MAIN #########################################//
//####################################################//

int main(int argc, char **argv) {
  if (parse_options(argc, argv) || argHelp || checkInput()) {
    show_usage(argc, argv);
    return 1;
  }

  return 0;
}

//####################################################//
//##### FUNCTIONS ####################################//
//####################################################//

//####################################################//
//##### UTILITIES ####################################//
//####################################################//

bool checkInput() {
  bool result = false;
  // result |= (argApxFName.length() == 0);
  // if (result) {
  //   std::cerr << "\033[0;31m[EE] ERROR - argApxFName is of zero
  //   length!!!\033[0m" << std::endl;
  // }
  return result;
}

//####################################################//
//##### DEBUG ########################################//
//####################################################//

//####################################################//
//##### GARBAGE / KEPT CODE ##########################//
//####################################################//

#if 0
{
}
#endif