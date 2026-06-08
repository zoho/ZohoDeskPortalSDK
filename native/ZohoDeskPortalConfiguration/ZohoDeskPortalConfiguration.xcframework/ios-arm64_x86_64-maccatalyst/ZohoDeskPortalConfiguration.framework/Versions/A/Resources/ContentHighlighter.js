//----------------------------------
//MARK: Highlighted the text by word
//----------------------------------

let highlighter = document.createElement("span");//No I18N
highlighter.className = "searchHighlighter";//No I18N

var currentIndex = 0
var searchCount = 0

let content = document.getElementById("editor");//No I18N
var after = 0

//Function to refresh search param and screen element
function refreshSearch() {
    currentIndex = 0
    searchCount = 0
    
    //Remove first search which is strong highlighted
    if (firstSelection = content.querySelector(".currentSearch")) {//No I18N
        firstSelection.classList.remove("currentSearch");//No I18N
    }
}

//To reset search param
function resetSearch() {
    after = 0
    refreshSearch()
    if (highlighted = content.querySelector(".searchHighlighter")) {//No I18N
        content.innerHTML = content.innerHTML.replace(new RegExp(highlighter.outerHTML.escapeCharacters(), "ig"), function(word) {//No I18N
            return word.replace(/<[^>]+>/g,"");//No I18N
        });
    }
}

function wordFinder({searchKeyword, isSingleIndexed = false, modifier = "ig"} = {}) {//No I18N
    
    /*
     ***Modifier***
     --------------
     i - To perform case-insensitive match
     g - To find all matches rather stop by first match
     */

    //Escape wildcard characters if any in search keyword
    searchKeyword = searchKeyword.escapeCharacters();
    
    //Refresh search param for each search
    refreshSearch()
    
    //Tags & character entities filter properties
    let pattern = new RegExp(`&\\w+;|(<[^>]*)?${searchKeyword}`, modifier);
    let ignore = new RegExp(`&\\w+;|(<[^>]*)`, modifier);
    
    if (highlighted = content.querySelector(".searchHighlighter")) {//No I18N
        content.innerHTML = content.innerHTML.replace(new RegExp(highlighted.outerHTML.escapeCharacters(), modifier), function(word) {
            return word.replace(/<[^>]+>/g,"");//No I18N
        });
        
        //Block to note the index for speech highlight
        if (isSingleIndexed) {
            if (content.innerHTML.length > after) {
                const contentText = content.innerHTML.slice(after)
                
                let pattern = new RegExp(`(<[^>]*)?${highlighter.innerHTML.escapeCharacters()}`, modifier);
                let ignore = new RegExp(`(<[^>]*)${highlighter.innerHTML.escapeCharacters()}`, modifier);
                
                while (match = pattern.exec(contentText)) {
                    if (!match[0].match(ignore)) {
                        after += pattern.lastIndex;
                        break;
                    }
                }
            } else { after = 0 }
        }
    }

    //Object to break iteration after first match
    let referenced = {
        highlightable: function(word) {
            if (!word.match(ignore)) {
                if (isSingleIndexed) {
                    referenced.highlightable = null;
                }
                highlighter.innerHTML = word;
                return highlighter.outerHTML;
            }
            return word;
        }
    }
    
    //Block to filter the matching keyword
    if (searchKeyword) {
        content.innerHTML = content.innerHTML.indexReplace(pattern, function(word) {
            if (referenced.highlightable) {
                return referenced.highlightable(word)
            }
            return word
        }, after);
    }
 
    updateSearchElement(!isSingleIndexed);
     
}

String.prototype.indexReplace = function(search, replace, from) {
    if (this.length > from) {
        return this.slice(0, from) + this.slice(from).replace(search, replace)
    }
    return this
}

//Notifier: Search result to native
function updateSearchElement(updateCount = true) {
    
    if (selectedElement = content.querySelectorAll(".searchHighlighter")) {//No I18N
        
        if (selectedElement.length) {
            
            if (!currentIndex) {currentIndex = 1;}
            searchCount = selectedElement.length
            
            const lookingSearch = selectedElement[currentIndex - 1];
            
            lookingSearch.classList.add("currentSearch");//No I18N
            
            const rect = lookingSearch.getBoundingClientRect()
            
            //---Patch---
            //The line has to rearranged,
            //in keyboard visible case auto scroll not working due to incorrect rect.
            //Platform has to analyse the issue regarding the case
            lookingSearch.scrollIntoViewIfNeeded();
            
            //Message handler to atuo-scroll to rect on screen
            window.webkit.messageHandlers.scrollToPosition.postMessage({x: 0, y: rect.y, width: rect.width, height: rect.height})
        }
        //Message handler for updating search count
        if (updateCount) {
            window.webkit.messageHandlers.searchIndexCounter.postMessage({currentIndex: currentIndex, totalCount: searchCount})
        }
    }
}

//Move highlight towards next search index
function moveDown() {
    
    if (searchCount == 0) {
        return
    }
    
    if (firstSelection = content.querySelector(".currentSearch")) {//No I18N
        firstSelection.classList.remove("currentSearch");//No I18N
    }
    currentIndex = (currentIndex + 1) % (searchCount + 1)
    if (currentIndex == 0) {
        currentIndex = 1;
    }
    updateSearchElement();
}

//Move highlight towards previous search index
function moveUp() {
    
    if (searchCount == 0) {
        return
    }
    
    if (firstSelection = content.querySelector(".currentSearch")) {//No I18N
        firstSelection.classList.remove("currentSearch");//No I18N
    }
    currentIndex = (currentIndex - 1) % (searchCount + 1);
    if (currentIndex == 0) {
        currentIndex = searchCount;
    }
    updateSearchElement();
}

//Escape wild card characters from string
String.prototype.escapeCharacters = function(){
    return this.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");//No I18N
}
