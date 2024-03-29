#ifndef searchTfIdf_h
#define searchTfIdf_h

#include <stdio.h>
#include "list.h"
#include "inverted.h"
#include "readData.h"
#include "myString.h"

List get_tf_idf_list(IList IL, List L, char **searchTerms, int nTerms);


#endif /* searchTfIdf_h */
