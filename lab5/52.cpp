/*

2 Build a B+ tree containing n = 14 nodes and having degree m = 5. Key values ​​in nodes
are set using a random number generator with a range D from 0 to 120
3 Ensure that trees are traversed "bottom-up".
4 Search for a key value by proximity from below.

*/

#include <string.h>
#include <time.h>

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int random();

const int MAX = 4;
const int MIN = 2;
int count_node = 0;
int min_ras = 1000;
int res_node;

struct btreeNode {
    int value[MAX + 1];
    int count;
    btreeNode *link[MAX + 1];
};

btreeNode *root;

btreeNode *createNode(int value, btreeNode *child) {
    btreeNode *newNode = new btreeNode;
    newNode->value[1] = value;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

void addvalueToNode(int value, int pos, btreeNode *node, btreeNode *child) {
    int j = node->count;
    while (j > pos) {
        node->value[j + 1] = node->value[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->value[j + 1] = value;
    node->link[j + 1] = child;
    node->count++;
}

void splitNode(int value, int *pvalue, int pos, btreeNode *node, btreeNode *child, btreeNode **newNode) {
    int median;
    int j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = new btreeNode;
    j = median + 1;
    while (j <= MAX) {
        (*newNode)->value[j - median] = node->value[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN) {
        addvalueToNode(value, pos, node, child);
    } else {
        addvalueToNode(value, pos - median, *newNode, child);
    }
    *pvalue = node->value[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

int setvalueueInNode(int value, int *pvalue, btreeNode *node, btreeNode **child) {
    int pos;
    if (!node) {
        *pvalue = value;
        *child = NULL;
        return 1;
    }
    if (value < node->value[1]) {
        pos = 0;
    } else {
        for (pos = node->count; (value < node->value[pos] && pos > 1); pos--)
            ;
        if (value == node->value[pos]) {
            cout << "Duplicate\n";
            return 0;
        }
    }
    if (setvalueueInNode(value, pvalue, node->link[pos], child)) {
        if (node->count < MAX) {
            addvalueToNode(*pvalue, pos, node, *child);
        } else {
            splitNode(*pvalue, pvalue, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

void insertion(int value) {
    int flag, valueue;
    btreeNode *child;
    flag = setvalueueInNode(value, &valueue, root, &child);
    if (flag) root = createNode(valueue, child);
}

void print(btreeNode *myNode, int gen) {
    int i;

    if (myNode) {
        cout << setw(2) << count_node << " Gen " << gen << " | ";
        count_node++;
        for (i = 0; i < myNode->count; i++) {
            cout << myNode->value[i + 1] << ' ';
        }
        cout << endl;
        for (i = 0; i < myNode->count; i++) {
            print(myNode->link[i], gen + 1);
        }
        print(myNode->link[i], gen + 1);
    }
}

void searching(int val, int *pos, btreeNode *myNode) {
    if (!myNode) {
        return;
    }

    if (val < myNode->value[1]) {
        *pos = 0;
    } else {
        for (*pos = myNode->count; (val < myNode->value[*pos] && *pos > 1); (*pos)--)
            ;
        if (val == myNode->value[*pos]) {
            cout << "Given data is Found\n";
            res_node = 1;
            return;
        }
    }
    searching(val, pos, myNode->link[*pos]);
    return;
}

void create_tree() {
    int rand;
    for (int i = 0; i < 14; i++) {
        rand = random();
        insertion(rand);
    }
    cout << "\nTree is:\n\n";
    print(root, 0);
}

int main() {
    time_t t;
    srand(time(&t));
    create_tree();
    int value;
    int vibor;
    while (true) {
        cout << "\n1. Searching\n2. Output\n3. Exit\n";
        cin >> vibor;
        cout << endl;
        switch (vibor) {
            case 1:
                res_node = 0;
                cout << "Enter the element to search:";
                cin >> value;
                searching(value, &vibor, root);
                if (!res_node) {
                    cout << "Given data no found!" << endl;
                }
                break;
            case 2:
                count_node = 0;
                print(root, 0);
                break;
            case 3:
                exit(0);
        }
        cout << endl;
    }
}

int random() {
    int rnd = rand() % (120 - 0 + 1);
    if (rnd < 0) {
        rnd *= -1;
    }
    cout << rnd << " ";
    return rnd;
}