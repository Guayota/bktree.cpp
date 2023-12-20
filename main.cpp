// TODO: write proper benchmarks with Google's benchmark library

#include <iostream>
#include <algorithm>
#include <chrono>
#include "csussus.cpp"
#define ASSERT(p, msg) if (!(p)) { std::cout << "[ASSERT ERROR]: " << msg << std::endl; exit(1); }

std::string words[] = {
    std::string("the"),
    std::string("be"),
    std::string("to"),
    std::string("of"),
    std::string("and"),
    std::string("a"),
    std::string("in"),
    std::string("that"),
    std::string("have"),
    std::string("I"),
    std::string("it"),
    std::string("for"),
    std::string("not"),
    std::string("on"),
    std::string("with"),
    std::string("he"),
    std::string("as"),
    std::string("you"),
    std::string("do"),
    std::string("at"),
    std::string("this"),
    std::string("but"),
    std::string("his"),
    std::string("by"),
    std::string("from"),
    std::string("they"),
    std::string("we"),
    std::string("say"),
    std::string("her"),
    std::string("she"),
    std::string("or"),
    std::string("an"),
    std::string("will"),
    std::string("my"),
    std::string("one"),
    std::string("all"),
    std::string("would"),
    std::string("there"),
    std::string("their"),
    std::string("what"),
    std::string("so"),
    std::string("up"),
    std::string("out"),
    std::string("if"),
    std::string("about"),
    std::string("who"),
    std::string("get"),
    std::string("which"),
    std::string("go"),
    std::string("me"),
    std::string("when"),
    std::string("make"),
    std::string("can"),
    std::string("like"),
    std::string("time"),
    std::string("no"),
    std::string("just"),
    std::string("him"),
    std::string("know"),
    std::string("take"),
    std::string("people"),
    std::string("into"),
    std::string("year"),
    std::string("your"),
    std::string("good"),
    std::string("some"),
    std::string("could"),
    std::string("them"),
    std::string("see"),
    std::string("other"),
    std::string("than"),
    std::string("then"),
    std::string("now"),
    std::string("look"),
    std::string("only"),
    std::string("come"),
    std::string("its"),
    std::string("over"),
    std::string("think"),
    std::string("also"),
    std::string("back"),
    std::string("after"),
    std::string("use"),
    std::string("two"),
    std::string("how"),
    std::string("our"),
    std::string("work"),
    std::string("first"),
    std::string("well"),
    std::string("way"),
    std::string("even"),
    std::string("new"),
    std::string("want"),
    std::string("because"),
    std::string("any"),
    std::string("these"),
    std::string("give"),
    std::string("day"),
    std::string("most"),
    std::string("us")
};

auto measure_func_nano(const std::function<void()>& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto finish = std::chrono::high_resolution_clock::now();
    return finish - start;
}

void benchmark_lev_distance() {
    std::cout << "Running benchmark_lev_distance()..." << std::endl;
    for (auto& s1 : words) {
        for (auto& s2 : words) {
            csus::lev_distance(s1, s2);
        }
    }
}

void benchmark_lev_distance_cstr() {
    std::cout << "Running benchmark_lev_distance_cstr()..." << std::endl;
    for (auto& s1 : words) {
        for (auto& s2 : words) {
            csus::lev_distance_cstr(s1.c_str(), s1.length(), s2.c_str(), s2.length());
        }
    }
}

void benchmark_lev_distance_substr() {
    std::cout << "Running benchmark_lev_distance_substr()..." << std::endl;
    for (auto& s1 : words) {
        for (auto& s2 : words) {
            csus::lev_distance_substr(s1, s2);
        }
    }
}

int main()
{
    //csus::bktree_str tree;
    //auto s1 = std::string("book");
    //auto s2 = std::string("sook");
    //size_t h = csus::lev_distance(s1, s2);
    //ASSERT(h == 1, "Distance between {book} and {shook} should be 1")
    //std::cout << h << "\n";
    {
        std::string stop;
        std::getline(std::cin, stop);
    }

    for (const auto f : { benchmark_lev_distance_substr, benchmark_lev_distance_cstr, benchmark_lev_distance }) {
        std::cout << "[MEASURE_FUNC_NANO] ";
        auto n = measure_func_nano(f);
        std::cout << "[MEASURE_FUNC_NANO] " << "Finished in " << n << std::endl;
    }
}
