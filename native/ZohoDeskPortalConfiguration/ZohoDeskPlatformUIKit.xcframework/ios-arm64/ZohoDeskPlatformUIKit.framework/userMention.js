var hasMentioned = false;

document.addEventListener("selectionchange", function() {// NO I18N
    onSelectionChange();
});

function getSelectedElement() {
    var selection = document.getSelection()
    if (selection.rangeCount > 0) {
        return selection.getRangeAt(0).startContainer.parentElement;
    }
    return null
}

function keyPressed(){
    const selectedElement = getSelectedElement()
    if (null != selectedElement) {
        if (selectedElement.innerText.includes("@")){// NO I18N
            var _selection = document.getSelection(),
            _anchorNode = _selection.anchorNode,
            range = _selection.getRangeAt(0),
            newRange = range.cloneRange(),
            contents,
            currText,
            textContent,
            pos;
            
            newRange.setStart(_anchorNode, 0);
            contents = newRange.cloneContents();
            textContent = contents.textContent;
            pos = textContent.lastIndexOf('@');
            currText = textContent.substr(pos + 1).trim();
            var text = textContent.substr(pos)
            var spaceCheck = text.includes(" ");
            var atCheck = text.charAt(0);
            if ( !spaceCheck && atCheck=="@") {
                caretOffset=document.getSelection().anchorNode.parentNode.offsetTop
                window.webkit.messageHandlers.zdplatformWebEditornotifier.postMessage("searchMention<1565593103>"+currText);// NO I18N
                //            fireURL("searchMention:"+currText);// No I18N
            } else {
                window.webkit.messageHandlers.zdplatformWebEditornotifier.postMessage("cancelMention"); // No I18N
            }
        }
    }
}

function fireURL(urlString){
    var iframe = document.createElement("IFRAME");// NO I18N
    iframe.setAttribute("src", urlString);// NO I18N
    document.documentElement.appendChild(iframe);
    iframe.parentNode.removeChild(iframe);
    iframe = null;
}


function replaceSuggestion(customTag){
    var _selection = document.getSelection()
    _selection.modify("extend", "backward", "word")// No I18N
    if (_selection.anchorNode.textContent.charAt(_selection.anchorOffset - 1) != '@') {
        _selection.modify("extend", "backward", "character")// No I18N
    }
    document.execCommand('insertHTML', true, customTag+"&nbsp");// No I18N
    return document.getElementById("editor").innerHTML
}



function getCursorPoint() {
    return document.getSelection().anchorNode.parentNode.offsetTop
}

function getElement(byId) {
    return document.getElementById(byId).textContent
}

function onSelectionChange() {
    const selectedElement = getSelectedElement()
    curateTagNames(window.getSelection().anchorNode, "", true)
    if (null != selectedElement) {
        const lineSeparatedInnerTexts = selectedElement.innerText.split('\n')
        if (hasMentioned && !lineSeparatedInnerTexts[0].includes('@')) {
            window.webkit.messageHandlers.zdplatformWebEditornotifier.postMessage("cancelMention"); // No I18N
        }
        hasMentioned = lineSeparatedInnerTexts[0].includes('@')
    }
}

function curateTagNames(element, attributes, canCurateChild) {
    if (element == null) {
        window.webkit.messageHandlers.zdplatformWebEditornotifier.postMessage("attributes:"+attributes) // No I18N
    }
    else if (element.tagName === undefined) {
        curateTagNames(element.parentElement, attributes, false)
    }
    else if (element.id != 'editor' && element != document.body && element != document) {
        const nonEssentialTags = ['li', 'div', 'teammention', 'agentmention', 'br'] // No I18N
        const separator = '~=' // No I18N
        if (canCurateChild) {
            attributes += appendChildTagNames(element, attributes, nonEssentialTags, separator, true)
        }
        const tagName = element.tagName.toLowerCase()
        if (color(element) != ''){
            attributes += 'forecolor' + separator // No I18N
        }
        if (!nonEssentialTags.includes(tagName)) {
            attributes += tagName + separator
        }
        curateTagNames(element.parentElement, attributes, false)
    } else {
        window.webkit.messageHandlers.zdplatformWebEditornotifier.postMessage("attributes:"+attributes); // No I18N
    }
}

function appendChildTagNames(element, attributes, nonEssentialTags, separator, isParentThread) {
    if (element == null) {return attributes}
    if (element.id == 'editor' || element === document.body || element === document) {return attributes}
    if (element.childNodes != undefined) {
        element.childNodes.forEach(childNode => {
            if (color(childNode) != ''){
                attributes += 'forecolor' + separator // No I18N
            }
            if (childNode.tagName != undefined) {
                if (!nonEssentialTags.includes(childNode.tagName.toLowerCase())) {
                    attributes += childNode.tagName.toLowerCase() + separator
                }
            }
            if (childNode.childElementCount != undefined) {
                if (childNode.childElementCount != 0) {
                    appendChildTagNames(childNode, attributes, nonEssentialTags, separator, false)
                }
            }
        });
    }
    if (isParentThread) {
        return attributes
    }
}

function color(element) {
    var color = ""
    if (!(element.style === undefined)){
        if (!(element.style.color === undefined) && (element.style.color != '')){
            color = element.style.color
        }
    }
    if (!(element.color === undefined)) {
        if (element.color != '') {
            color = element.color
        }
    }
    return color
}
