#include <boost/program_options.hpp>
#include <iostream>

#include <pulsar/pulsar.h>
#include <pulsar/cryptography.h>

int main(int argc, char* argv[]) {
    namespace po = boost::program_options;
    po::options_description desc("Options");

    desc.add_options()
            ("help,h", "Display this help message")
            ("version,v", "Display the version number")
            ("config,c", po::value<std::string>(),"Path to config file");

    auto usage = [&desc]() -> int {
        std::cout <<  "Usage: pulsar [options]" << std::endl << desc << std::endl;
        return EXIT_FAILURE;
    };

    try {
        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            return usage();
        }

        if (vm.count("version")) {
            // TODO: get pulsar version
            std::cout << "unknown" << std::endl;
            return EXIT_SUCCESS;
        }

        if (vm.count("config")) {
            const auto &filename = vm["config"].as<std::string>();
            std::cout << "Load config: " << filename << std::endl;
            // LoadFromConfig(filename);
            pulsar::CryptographyScheme cs("");
            cs.Sign(nullptr);

            return EXIT_SUCCESS;
        }

    }
    catch (std::exception const& e) {
        std::cerr << "Failed to parse options: " << e.what() << std::endl;
    }

    return usage();
}
