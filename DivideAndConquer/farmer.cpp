#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

//所有动作
enum Action {
    FARMER_GO = 0,
    FARMER_WOLF_GO,
    FARMER_SHEEP_GO,
    FARMER_VEGETABLE_GO,
    FARMER_RETURN,
    ARMER_WOLF_RETURN,
    FARMER_SHEEP_RETURN,
    FARMER_VEGETABLE_RETURN,
    NOACTION
};

//动作的描述
string actionDescription[] =
        {
                "农夫过河",
                "农夫带狐狸过河",
                "农夫带鸡过河",
                "农夫带米过河",
                "农夫返回",
                "农夫带狐狸返回",
                "农夫带鸡返回",
                "农夫带米返回",
                "无动作"
        };

//状态(搜索节点)
struct State {
    bool farmer, wolf, sheep, vegetable; //0表示在河这边，1表示在河对岸
    Action nextAction; //下一步的动作

    //构造函数
    State() {

    }

    State(bool farmer, bool wolf, bool sheep, bool vegetable) {
        this->farmer = farmer;
        this->wolf = wolf;
        this->sheep = sheep;
        this->vegetable = vegetable;
        nextAction = NOACTION;
    }

    //重载==运算符
    bool operator==(const State &s) {
        return (farmer == s.farmer && wolf == s.wolf && sheep == s.sheep && vegetable == s.vegetable);
    }

    //打印
    void print() {
        cout << farmer << " " << wolf << " " << sheep << " " << vegetable << " " << actionDescription[nextAction]
             << endl;
    }
};

typedef bool(*PROCESS)(const State &current, State &next);

//八种动作的处理函数
bool ProcessFarmerGo(const State &current, State &next) {
    if (current.farmer) {
        return false;
    }
    next = current;
    next.farmer = true;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerWolfGo(const State &current, State &next) {
    if (current.farmer || current.wolf) {
        return false;
    }
    next = current;
    next.farmer = next.wolf = true;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerSheepGo(const State &current, State &next) {
    if (current.farmer || current.sheep) {
        return false;
    }
    next = current;
    next.farmer = next.sheep = true;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerVegetablepGo(const State &current, State &next) {
    if (current.farmer || current.vegetable) {
        return false;
    }
    next = current;
    next.farmer = next.vegetable = true;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerReturn(const State &current, State &next) {
    if (!current.farmer) {
        return false;
    }
    next = current;
    next.farmer = false;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerWolfReturn(const State &current, State &next) {
    if (!current.farmer || !current.wolf) {
        return false;
    }
    next = current;
    next.farmer = next.wolf = false;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerSheepReturn(const State &current, State &next) {
    if (!current.farmer || !current.sheep) {
        return false;
    }
    next = current;
    next.farmer = next.sheep = false;
    next.nextAction = NOACTION;
    return true;
}

bool ProcessFarmerVegetablepReturn(const State &current, State &next) {
    if (!current.farmer || !current.vegetable) {
        return false;
    }
    next = current;
    next.farmer = next.vegetable = false;
    next.nextAction = NOACTION;
    return true;
}

//处理函数列表
PROCESS process[] =
        {
                ProcessFarmerGo,
                ProcessFarmerWolfGo,
                ProcessFarmerSheepGo,
                ProcessFarmerVegetablepGo,
                ProcessFarmerReturn,
                ProcessFarmerWolfReturn,
                ProcessFarmerSheepReturn,
                ProcessFarmerVegetablepReturn
        };

//标记已搜索的状态
vector<State> visitedStates;

//判断状态是否合法
bool IsStateLegal(const State &state) {
    return !((state.wolf == state.sheep && state.wolf != state.farmer) ||
             (state.vegetable == state.sheep && state.sheep != state.farmer));
}

//标记状态为已搜索
void BookState(const State state) {
    visitedStates.push_back(state);
}

//取消标记当前状态
void PopState() {
    visitedStates.pop_back();
}

//判断状态是否被访问过
bool HasVisited(const State &state) {
    return (find(visitedStates.begin(), visitedStates.end(), state) != visitedStates.end());
}

//判断是否是目标状态
bool IsTargetState(const State &state) {
    return (state.farmer && state.wolf && state.sheep && state.vegetable);
}

//输出结果
void PrintResult() {
    for (int i = 0; i < visitedStates.size(); ++i) {
        cout << actionDescription[visitedStates[i].nextAction] << endl;
    }
    cout << endl;
}

int cSolution; //解的数目

void dfs(State currentState) {
    //被访问过
    if (HasVisited(currentState)) {
        return;
    }

    //状态不合法
    if (!IsStateLegal(currentState)) {
        return;
    }

    //达到目标状态
    if (IsTargetState(currentState)) {
        cSolution++;
        cout << "Solution " << cSolution << ":" << endl;
        PrintResult();
        return;
    }

    //枚举所有可能动作
    for (int i = FARMER_GO; i <= FARMER_VEGETABLE_RETURN; ++i) {
        State nextState;
        if (process[i](currentState, nextState)) {
            //记录当前状态的nextAction
            currentState.nextAction = (Action) i;
            //标记当前状态
            BookState(currentState);
            //继续搜索
            dfs(nextState);
            //取消标记当前状态
            PopState();
        }
    }
}

TEST(farmer, farmer) {
//从初始状态开始搜索
    dfs(State(false, false, false, false));
}