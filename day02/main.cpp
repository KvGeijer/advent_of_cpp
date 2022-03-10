#include <iostream>
#include <vector>


std::vector<int> scan()
{
    int num;
    std::string read;
    std::vector<int> code;

    while (std::getline(std::cin, read, ','))
    {
        code.push_back(std::stoi(read));
    }

    // What actually happens here? Are we returning pointer? Or copying? And so on...
    return code;
}

void print_code(std::vector<int> &code)
{
    for (int i : code) {
        std::cout << i << ',';
    }

    std::cout << std::endl;
}


void parse(std::vector<int>& code)
{
    int pos = 0;

    while (true)
    {
        switch (code[pos]) {
            case 1:
            code[code[pos+3]] = code[code[pos + 1]] + code[code[pos + 2]];
            break;

            case 2:
            code[code[pos+3]] = code[code[pos + 1]] * code[code[pos + 2]];
            break;

            case 99:
            return;

            default:
            perror("Invalid op-code");
        }
        pos += 4;

    }
}


void part1(std::vector<int> code)
{


    code[1] = 12;   // noun
    code[2] = 2;    // verb

    parse(code);
    std::cout << "The 1202 result: " << code[0] << std::endl;

}


bool try_start(std::vector<int> code, int noun, int verb)
{
    code[1] = noun;
    code[2] = verb;

    parse(code);
    return code[0] == 19690720;
}


int brute_force(std::vector<int> code)
{

    for (int layer = 0;; layer++)
    {
        for (int noun = 0; noun < layer; noun++)
        {
            if (try_start(code, noun, layer)) {
                return 100 * noun + layer;
            }
        }

        for (int verb = 0; verb <= layer; verb++)
        {
            if (try_start(code, layer, verb)) {
                return 100 * layer + verb;;
            }
        }
    }
}


void part2(std::vector<int> code)
{

    int result = brute_force(code);
    std::cout << "The multiplication of calid noun and verb: " << result << std::endl;

}


int main()
{

    auto code = scan();
    part1(code);
    part2(code);

}