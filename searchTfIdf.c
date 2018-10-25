//
//  searchTfIdf.c
//  Ass2
//
//

#include "searchTfIdf.h"

List get_tf_idf_list(IList IL, List collectionL, char **searchTerms, int nTerms) {
    
    List tf_idf_list = NULL;
    
    for (int i = 0; i < nTerms; i++) {
        
        BSTNode *wordNode = IListSearch(IL, searchTerms[i]);
        
        Node *curr = wordNode->urlList;
        while (curr != NULL) {
            
            Node *tf_idf_list_node = inLL(tf_idf_list, curr->url);
            //if url not in LL, add and initialise it
            if(tf_idf_list_node == NULL) {
                tf_idf_list = insertLL(tf_idf_list, curr->url);
                tf_idf_list_node = inLL(tf_idf_list, curr->url);
                Node *collNode = inLL(collectionL, curr->url);
                tf_idf_list_node->nWords = collNode->nWords;
                tf_idf_list_node->tf_idf = 0;
                tf_idf_list_node->matchCount = 0;
            }
            
            tf_idf_list_node->tf_idf += wordNode->idf *
                ((float)curr->matchCount/(float)tf_idf_list_node->nWords);
            
            tf_idf_list_node->matchCount++;
            
            curr = curr->next;
        }
    }
    
    return tf_idf_list;
}
