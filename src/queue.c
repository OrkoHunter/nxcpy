#include "queue.h"

/* Create empty Queue */
struct Queue *init_queue() {
    struct Queue *QH;
    QH = (struct Queue *)malloc(sizeof(struct Queue));
    QH->last = NULL;
    QH->first = NULL;

    return QH;
}

/* Function to remove an element from Queue and return the node */
int dequeue(struct Queue *QH) {
    int to_return;
    if (QH->first == NULL && QH->last == NULL) {
        printf("Queue is already empty.\n");
    }
    else {
        to_return = QH->first->data;
        if (QH->first == QH->last) {
            QH->first = NULL;
            QH->last = NULL;
        }
        else {
            QH->first = QH->first->back;
            QH->first->next = NULL;

        return to_return;
        }
    }
}

/* Function to add an element to the Queue */
void enqueue(struct Queue *QH, int data) {
    if (QH->last != NULL) {
        QH->last->back = (struct qNode *)malloc(sizeof(struct qNode));
        QH->last->back->next = QH->last;
        QH->last = QH->last->back;
        QH->last->back = NULL;
        QH->last->data = data;
    }
    else if(QH->last == NULL) {
        struct qNode *temp;
        temp = (struct qNode *)malloc(sizeof(struct qNode));
        temp->back = NULL;
        temp->next = NULL;
        temp->data = data;
        QH->last = temp;
        QH->first = temp;
    }
}

/* Print out the elements in the queue */
void print_queue(struct Queue *QH) {
    struct qNode *iter = QH->first;
    printf("%d ", iter->data);
    while (true) {
        if (iter->back==NULL) {
            break;
        }
        else
            iter = iter->back;
            printf("-> %d ", iter->data);
    }
    printf("\n");
}
