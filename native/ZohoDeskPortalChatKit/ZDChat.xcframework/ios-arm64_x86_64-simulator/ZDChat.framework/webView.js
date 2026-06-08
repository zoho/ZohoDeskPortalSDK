
function didThemeUpdate(isDark) {
    
    var tags = document.getElementsByTagName("iFrame"); // No i18N
    for(i=0;i<tags.length;i++){
        tags[i].style.filter = isDark ? "invert(1)": "invert(0)"; // No i18N
        tags[i].style.webFilter = isDark ? "invert(1)": "invert(0)"; // No i18N
    }
}

function updateTheme(isDarkTheme) {
    var isDark = isDarkTheme == "true"; // No i18N
    document.body.style.color = isDark ? 'white' : 'black'; // No i18N
}

function supportAction() {
    window.webkit.messageHandlers.SupportAction.postMessage({SupportAction: document.body.scrollHeight});
}
