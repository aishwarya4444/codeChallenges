/*
https://www.interviewbit.com/problems/allocate-books/
https://www.youtube.com/watch?v=Ss9ta1zmiZo&t=1335s
*/

bool check(vector<int> &A, int limit, int B) {
    int students = 1, pages = 0;

    for(int book: A) {
        if(pages+book > limit) {
            pages = book;
            students++;
            if(students > B) {
                return false;
            }
        } else {
            pages += book;
        }
    }

    // return students<=B;
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int start = 0, mid, end = 0, result = -1;

    if(A.size() < B) {
        return result;
    }

    for(int book: A) {
        end += book;
        start = max(start, book);
    }

    while(start<=end) {
        mid = (end-start)/2+start;
        if(check(A, mid, B)) {
            result = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return result;

}
