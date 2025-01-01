#include <iostream>
#include "Graph.h"
#include "BinarySearchTree.h"
#include "Sorting.h"

using namespace std;

void menu_display() {
    cout << "Welcome to the Multi-Utility System!"
        <<" Please choose an option from the main menu. :\n";
    cout << "1. Graph Pathfinding(the shortest path): \n";
    cout << "2. Binary Search Tree Operations: \n";
    cout << "3. Sorting Functions(Merge & Quick ):\n";
    cout << "4. Exit\n";
}

void menu_of_graph(Graph& graph) {
    int graph_choice;
    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Add edge between vertices\n";
        cout << "2. Dijkstra's algorithm\n";
        cout << "3. Back to main menu\n";
        cout << "Enter your choice: ";
        while (!(cin >> graph_choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (graph_choice) {
        case 1: {
            int u, v, weight;
            cout << "Enter source, destination, and weight: ";
            cin >> u >> v >> weight;
            graph.addEdge(u, v, weight);
            break;
        }
        case 2: {
            int start, end;
            cout << "Enter start and end vertices: ";
            cin >> start >> end;
            graph.dijkstra(start, end);
            break;
        }
        case 3:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (graph_choice != 3);
}

void menu_of_trees(BinarySearchTree& bst) {
    int tree_choice;
    do {
        cout << "\nBST Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Back to main menu\n";
        cout << "Enter your choice: ";
        while (!(cin >> tree_choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (tree_choice) {
        case 1: {
            int value;
            cout << "Enter value to insert: ";
            while (!(cin >> value)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            bst.insert(value);
            break;
        }
        case 2: {
            int value;
            cout << "Enter value to delete: ";
            while (!(cin >> value)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            bst.deleteNode(value);
            break;
        }
        case 3:
            cout << "Inorder Traversal: ";
            bst.InOrderTraversal();
            break;
        case 4:
            cout << "Preorder Traversal: ";
            bst.PreOrderTraversal();
            break;
        case 5:
            cout << "Postorder Traversal: ";
            bst.PostOrderTraversal();
            break;
        case 6:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (tree_choice != 6);
}

void menu_of_sorting() {
    int sorting_choice;
    do {
        cout << "\nSorting Menu:\n";
        cout << "1. Sort array using Merge Sort\n";
        cout << "2. Sort array using Quick Sort\n";
        cout << "3. Back to main menu\n";
        cout << "Enter your choice: ";
        while (!(cin >> sorting_choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (sorting_choice) {
        case 1: {
            int size;
            cout << "Enter size of array: ";
            while (!(cin >> size) || size <= 0) {
                cout << "Invalid input. Please enter a positive integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int* arr = new int[size];
            cout << "Enter array elements: ";
            for (int i = 0; i < size; ++i) cin >> arr[i];

            int comparisons = 0, swaps = 0;
            Sorting sorter;
            sorter.mergeSort(arr, 0, size - 1, comparisons, swaps);

            cout << "Sorted array: ";
            for (int i = 0; i < size; ++i) cout << arr[i] << " ";
            cout << "\nComparisons: " << comparisons << ", Swaps: " << swaps << "\n";

            delete[] arr;
            break;
        }
        case 2: {
            int size;
            cout << "Enter size of array: ";
            while (!(cin >> size) || size <= 0) {
                cout << "Invalid input. Please enter a positive integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            int* arr = new int[size];
            cout << "Enter array elements: ";
            for (int i = 0; i < size; ++i) cin >> arr[i];

            int comparisons = 0, swaps = 0;
            Sorting sorter;
            sorter.quickSort(arr, 0, size - 1, comparisons, swaps);

            cout << "Sorted array: ";
            for (int i = 0; i < size; ++i) cout << arr[i] << " ";
            cout << "\nComparisons: " << comparisons << ", Swaps: " << swaps << "\n";

            delete[] arr;
            break;
        }
        case 3:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (sorting_choice != 3);
}

int main() {
    int choice;
    Graph graph(10); // Example graph with 10 nodes
    BinarySearchTree bst;

    do {
        menu_display();
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
        case 1:
            menu_of_graph(graph);
            break;
        case 2:
            menu_of_trees(bst);
            break;
        case 3:
            menu_of_sorting();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
