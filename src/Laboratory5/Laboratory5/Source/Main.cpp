#include "../Header/Main.h"

int main()
{
    setlocale(LC_ALL, "");

    BinaryTree* binaryTree = new BinaryTree();
    Treap* treap = new Treap();
    int action = 0;
    bool flag = true;

    while (flag)
    {
        switch (action)
        {
        case 1:
        {
            cout << "Текущее Бинарное дерево: " << endl;
            PrintBinaryTree(binaryTree->Root, true, {}, {}, {}, true, false, nullptr);
            cout << "Действия:" << endl;
            cout << "1. Добавить элемент" << endl;
            cout << "2. Удалить элемент" << endl;
            cout << "3. Найти элемент" << endl;
            cout << "4. Найти минимальный элемент" << endl;
            cout << "5. Найти максимальный элемент" << endl;
            cout << "0. Вернуться к выбору структуры" << endl << endl;

            int userCommand = CheckData();
            system("cls");
            switch (userCommand)
            {
            case 1:
            {
                cout << "1. Введите значение для вставки: ";
                int value = CheckData();
                Insert(binaryTree->Root, value);
                break;
            }
            case 2:
            {
                cout << "2. Введите значение для удаления: ";
                int value = CheckData();
                Remove(binaryTree->Root, value);
                break;
            }
            case 3:
            {
                cout << "3. Введите значение для поиска: ";
                int valueToFind = CheckData();
                try
                {
                    BinaryTreeNode* node = Find(binaryTree->Root, valueToFind);
                    if (node != nullptr)
                        cout << "Найдено значение: " << node->Data << endl;
                    else
                        cout << "Значение не найдено." << endl;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4:
            {
                try
                {
                    BinaryTreeNode* minNode = FindMin(binaryTree->Root);
                    if (minNode != nullptr)
                        cout << "Минимальное значение: " << minNode->Data << endl;
                    else
                        cout << "Дерево пусто." << endl;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 5:
            {
                try
                {
                    BinaryTreeNode* maxNode = FindMax(binaryTree->Root);
                    if (maxNode != nullptr)
                        cout << "Максимальное значение: " << maxNode->Data << endl;
                    else
                        cout << "Дерево пусто." << endl;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 0:
            {
                action = 0;
                break;
            }
            default:
            {
                cout << "Неверная команда!" << endl;
                break;
            }
            }

            break;
        }
        case 2:
        {
            cout << "Текущее Декартово дерево: " << endl;
            PrintTreap(treap->Root, true, {}, {}, {}, true, false, nullptr);
            cout << "Действия:" << endl;
            cout << "1. Добавить элемент" << endl;
            cout << "2. Удалить элемент" << endl;
            cout << "3. Добавить оптимизированный элемент" << endl;
            cout << "4. Удалить оптимизированный элемент" << endl;
            cout << "5. Найти элемент" << endl;
            cout << "0. Вернуться к выбору структуры" << endl << endl;

            int cmd = CheckData();
            system("cls");
            switch (cmd)
            {
            case 1:
            {
                cout << "1. Введите значение: ";
                int value = CheckData();
                AddUnoptimized(treap->Root, value);
                break;
            }
            case 2:
            {
                cout << "2. Введите ключ: ";
                int key = CheckData();
                bool success = true;
                try
                {
                    RemoveUnoptimized(treap->Root, key, success);
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
                break;
            }
            case 3:
            {
                cout << "3. Введите значение: ";
                int value = CheckData();
                AddOptimized(treap->Root, value);
                break;
            }
            case 4:
            {
                cout << "4. Введите ключ: ";
                int key = CheckData();
                bool success = true;
                try
                {
                    RemoveOptimized(treap->Root, key, success);
                }
                catch (exception& e)
                {
                    cout << e.what() << '\n';
                }
                break;
            }
            case 5:
            {
                cout << "5. Введите ключ: ";
                int key = CheckData();
                try
                {
                    cout << "Найдено значение: " << GetValue(treap->Root, key) << endl;
                }
                catch (exception& e)
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 0:
            {
                action = 0;
                break;
            }
            default:
            {
                cout << "Неверная команда!" << endl;
                break;
            }
            }

            break;
        }
        default:
        {
            cout << "Выберите структуру:" << endl;
            cout << "1 -  Бинарное дерево" << endl;
            cout << "2 - Декартово дерево" << endl;
            cout << "0 - Выход из программы" << endl << endl;
            SelectAction(action, flag);
            break;
        }
        }
    }
    delete binaryTree;
    delete treap;
    return 0;
}

static int CheckData()
{
    cout << "Ваш ввод: ";

    string input;

    while (true)
    {
        try
        {
            cin >> input;
            size_t pos;
            // попытка преобразовать строку в число
            int value = stoi(input, &pos);
            // проверка на то, все ли символы строки преобразованы.
            if (pos == input.length())
            {
                return value;
            }
            else
            {
                cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
            }
        }
        catch (invalid_argument& e)
        {
            cout << "Введено неверное значение (не число). Повторите ввод: ";
        }
    }
}

void SelectAction(int& action, bool& flag)
{
    int newAction = CheckData();
    system("cls");
    if (newAction == 0)
    {
        flag = false;
    }
    else if (newAction >= 1 && newAction < 3)
    {
        action = newAction;
    }
    else
    {
        cout << "Неверная команда!" << endl;
    }
}

void PrintBinaryTree(BinaryTreeNode const* node, bool isHigh, vector<string> const& leftPrefix, vector<string> const& centerPrefix, vector<string> const& rightPrefix, bool isRoot, bool isLeftChild, shared_ptr<vector<vector<string>>> lines)
{
    if (!node) return;

    // Определяем тип вектора строк
    typedef vector<string> StringVector;

    // Лямбда-функция для объединения двух векторов строк
    auto ConcatenateVectors = [](StringVector const& a, StringVector const& b) { auto result = a; result.insert(result.end(), b.begin(), b.end()); return result; };

    // Если это корень, создаем новый вектор строк для хранения строк
    if (isRoot)
        lines = make_shared<vector<StringVector>>();

    if (node->Left)
        PrintBinaryTree(node->Left, isHigh, ConcatenateVectors(leftPrefix, isHigh ? StringVector({ " ", " " }) : StringVector({ " " })),
            ConcatenateVectors(leftPrefix, isHigh ? StringVector({ "/", "|" }) : StringVector({ "/" })),
            ConcatenateVectors(leftPrefix, isHigh ? StringVector({ "-", " " }) : StringVector({ "-" })),
            false, true, lines);

    // Форматируем значение текущего узла
    auto nodeValueString = "[" + to_string(node->Data) + "]";
    size_t midpointIndex = isLeftChild || nodeValueString.empty() ? nodeValueString.size() / 2 : ((nodeValueString.size() + 1) / 2 - 1);

    // Добавляем символы узла в вектор строк для вывода
    for (size_t i = 0; i < nodeValueString.size(); ++i)
    {
        lines->push_back(ConcatenateVectors(i < midpointIndex ? leftPrefix : i == midpointIndex ? centerPrefix : rightPrefix, { string(1, nodeValueString[i]) }));
    }

    if (node->Right)
        PrintBinaryTree(node->Right, isHigh, ConcatenateVectors(rightPrefix, isHigh ? StringVector({ "-", " " }) : StringVector({ "-" })),
            ConcatenateVectors(rightPrefix, isHigh ? StringVector({ "\\", "|" }) : StringVector({ "\\" })),
            ConcatenateVectors(rightPrefix, isHigh ? StringVector({ " ", " " }) : StringVector({ " " })),
            false, false, lines);

    if (isRoot)
    {
        StringVector outputLines;
        for (size_t lineIndex = 0;; ++lineIndex)
        {
            bool isLastLine = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (lineIndex < (*lines).at(i).size())
                {
                    line += lines->at(i)[lineIndex];
                    isLastLine = false;
                }
                else
                    line += " ";
            if (isLastLine) break;
            outputLines.push_back(line);
        }
        for (size_t i = 0; i < outputLines.size(); ++i)
            cout << outputLines[i] << endl;
    }
}

void PrintTreap(TreapNode const* node, bool isHigh, vector<string> const& leftPrefix, vector<string> const& centerPrefix, vector<string> const& rightPrefix, bool isRoot, bool isLeftChild, shared_ptr<vector<vector<string>>> lines)
{
    if (!node) return;

    // Определяем тип вектора строк
    typedef vector<string> StringVector;

    // Лямбда-функция для объединения двух векторов строк
    auto ConcatenateVectors = [](StringVector const& a, StringVector const& b) { auto result = a; result.insert(result.end(), b.begin(), b.end()); return result; };

    // Если это корень, создаем новый вектор строк для хранения строк
    if (isRoot) lines = make_shared<vector<StringVector>>();

    if (node->LeftNode)
        PrintTreap(node->LeftNode, isHigh, ConcatenateVectors(leftPrefix, isHigh ? StringVector({ " ", " " }) : StringVector({ " " })),
            ConcatenateVectors(leftPrefix, isHigh ? StringVector({ "/", "|" }) : StringVector({ "/" })),
            ConcatenateVectors(leftPrefix, isHigh ? StringVector({ "-", " " }) : StringVector({ "-" })),
            false, true, lines);

    // Форматируем значение текущего узла с приоритетом
    auto nodeValueString = "[" + to_string(node->Key) + "] (Значение приоритета: " + to_string(node->Priority) + ")";
    size_t midpointIndex = isLeftChild || nodeValueString.empty() ? nodeValueString.size() / 2 : ((nodeValueString.size() + 1) / 2 - 1);

    // Добавляем символы узла в вектор строк для вывода
    for (size_t i = 0; i < nodeValueString.size(); ++i)
    {
        lines->push_back(ConcatenateVectors(i < midpointIndex ? leftPrefix : i == midpointIndex ? centerPrefix : rightPrefix, { string(1, nodeValueString[i]) }));
    }

    if (node->RightNode)
        PrintTreap(node->RightNode, isHigh, ConcatenateVectors(rightPrefix, isHigh ? StringVector({ "-", " " }) : StringVector({ "-" })),
            ConcatenateVectors(rightPrefix, isHigh ? StringVector({ "\\", "|" }) : StringVector({ "\\" })),
            ConcatenateVectors(rightPrefix, isHigh ? StringVector({ " ", " " }) : StringVector({ " " })),
            false, false, lines);

    if (isRoot)
    {
        StringVector outputLines;
        for (size_t lineIndex = 0;; ++lineIndex)
        {
            bool isLastLine = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (lineIndex < (*lines).at(i).size())
                {
                    line += lines->at(i)[lineIndex];
                    isLastLine = false;
                }
                else
                    line += " ";
            if (isLastLine) break;
            outputLines.push_back(line);
        }
        for (size_t i = 0; i < outputLines.size(); ++i)
            cout << outputLines[i] << endl;
    }
}



