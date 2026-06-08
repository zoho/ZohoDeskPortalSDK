function enhanceReadabilityForDarkTheme() {
    var elements = document.querySelectorAll('a,span,p,b,pre,li,font,div,table,td,tr,tbody,i,sub,sup,u,h1,h2,h3,h4,h5,h6,em,strong,ol,ul,li,br,BIG,SMALL,th,s,strike,center,form,tt,nobr,frame,frameset,dl,dt,dd,section,code'); //No I18n
    for(let i = 0; i < elements.length; i++) {
        var link = false;

        var element = elements[i];
        var newClass = element.className;
        var color = element.style.color;
        var bgColor = element.style.backgroundColor;
        var isInvertable = !(element.classList.contains("KB_New_Editor_Highlights") || element.parentElement.classList.contains("KB_New_Editor_Highlights"))//NO I18N
        
        if (!bgColor) {
            bgColor = element.parentElement.style.backgroundColor;
        }

        if(element.closest('a')) {
             if (!element.classList.contains('desk_link')) { //No I18n
                newClass = newClass.concat(' desk_link'); //No I18n
              }
            link = true;
        }

    //         convert text color to hex format

        const textTags = ['p','b','pre','li','font','i','sub','sup','u','h1','h2','h3','h4','h5','h6','em','strong','li','big','small','s','strike', 'div', 'th', 'td', 'dt', 'dd', 'span', 'a']; //No I18n
        if(!color) {
            if(textTags.includes(element.tagName.toLowerCase())) {
                color = "#000000";//NO I18N
            }
        }

    //      convert text color to hex format

        if (convertTxtToHex(bgColor)) {
              bgColor = convertTxtToHex(bgColor);
        }

        if(convertTxtToHex(color)) {
            color = convertTxtToHex(color);
        }

    //         convert hex to RGB format

        if (hexToRgb(bgColor)) {
              bgColor = hexToRgb(bgColor);
        }
        if (hexToRgb(color)) {
              color = hexToRgb(color);
        }

        if(bgColor && color) {
            var rgbBack = trimRGB(bgColor);
            if (rgbBack[0] > 200 && rgbBack[1] > 200 && rgbBack[2] > 200 && isInvertable) {

                if (!element.classList.contains('desk_change_bg') && newClass.indexOf("desk_change_bg") == -1) { //No I18n
                    newClass = newClass.concat(' desk_change_bg') //No I18n
                }
                var rgb = trimRGB(color);
                var hexColor = 0x232B38; // add dark mode background color
                var o = contrast([parseInt(rgb[0]), parseInt(rgb[1]), parseInt(rgb[2])],[(hexColor >> 16) & 0xFF, (hexColor >> 8) & 0xFF, (hexColor) & 0xFF]);
                if (o < 3) {
                    if (!link && !element.classList.contains('desk_change_fg')) { //NO I18N
                        newClass = newClass.concat(' desk_change_fg'); //NO I18N
                    }
                }
                
              } else {
                var rgb = trimRGB(color);
                var o = contrast([parseInt(rgbBack[0]), parseInt(rgbBack[1]), parseInt(rgbBack[2])], [parseInt(rgb[0]), parseInt(rgb[1]), parseInt(rgb[2])]);
                if (o < 3) {
                      var newO = contrast([parseInt(rgbBack[0]), parseInt(rgbBack[1]), parseInt(rgbBack[2])], [0, 0, 0]);
                      if (newO < 3) {
                        if (!link && !element.classList.contains('desk_change_fg')) { //NO I18N
                          newClass = newClass.concat(' desk_change_fg'); //NO I18N
                        }
                      } else {
                        if (!element.classList.contains('desk_change_fg_black')) { //NO I18N
                          newClass = newClass.concat(' desk_change_fg_black'); //NO I18N
                        }
                      }
                } else {
                    element.style.color = color
                }

            }

        } else if(color) {

            var jsParentElement = element.parentElement;
            
            var newBgColor;
            while(jsParentElement) {
                if(jsParentElement.style.backgroundColor || jsParentElement.style.background) {

                    var backgroundColor = jsParentElement.style.backgroundColor;
                    if(backgroundColor) {
                        if(convertTxtToHex(backgroundColor)) {
                            backgroundColor = convertTxtToHex(backgroundColor);
                        }

                        if(hexToRgb(backgroundColor)) {
                            backgroundColor = hexToRgb(backgroundColor);
                        }
                    }

                    if(!backgroundColor) {
                        backgroundColor = jsParentElement.style.background;
                        if(convertTxtToHex(backgroundColor)) {
                            backgroundColor = convertTxtToHex(backgroundColor);
                        }

                        if(hexToRgb(backgroundColor)) {
                            backgroundColor = hexToRgb(backgroundColor);
                        }
                    }

                    var tempBgColor = trimRGB(backgroundColor);
                    if(tempBgColor && (!(tempBgColor[0] > 200 && tempBgColor[1] > 200 && tempBgColor[2] > 200) || isInvertable)) {
                        newBgColor = backgroundColor ;
                        break;
                    }
                }
                jsParentElement = jsParentElement.parentElement;
            }
            
            var rgb = trimRGB(color);
            if (!newBgColor) {
                newBgColor = rgb;
            } else {
                newBgColor = trimRGB(newBgColor);
            }
            var o = contrast([parseInt(rgb[0]), parseInt(rgb[1]), parseInt(rgb[2])], [parseInt(newBgColor[0]), parseInt(newBgColor[1]), parseInt(newBgColor[2])]);
            
            if (o < 3) {
                if (!link && !element.classList.contains('desk_link')) { //NO I18N
                      newClass = newClass.concat(' desk_change_fg'); //NO I18N
                }
              }

        } else if(bgColor) {
            var rgb = trimRGB(bgColor);
              if (rgb[0] > 200 && rgb[1] > 200 && rgb[2] > 200 && isInvertable) {
                    if (!element.classList.contains('desk_change_bg')) { //NO I18N
                        newClass = newClass.concat(' desk_change_bg');  //NO I18N
                    }
                
              } else{
                var hexColor=0xe1e1e1;
                var o = contrast([parseInt(rgb[0]), parseInt(rgb[1]), parseInt(rgb[2])], [(hexColor >> 16) & 0xFF, (hexColor >> 8) & 0xFF, (hexColor) & 0xFF]);
                if(o<3) {
                    if (!element.classList.contains('desk_change_fg_black')) { //NO I18N
                    newClass = newClass.concat(' desk_change_fg_black'); //NO I18N
                    }
                }
              }

        }

       element.className = newClass;

    }


}


function getElementColor(element) {
    // body...
    var color = element.style.color;

    if(!color && element.color !== undefined) {
        color = element.color;
    }

    if(typeof color === 'string' && color == '') {//NO I18N
        color = "#000000";//NO I18N
    }
    return color;

}

function getElementBgColor(element) {
    // body...
    var bgColor = element.style.backgroundColor;

    if(!bgColor) {
        bgColor = element.style.background;
    }

    if (!bgColor && element.bgColor !== undefined) {
        bgColor = element.bgColor;
    }

    return bgColor;
}
function trimRGB(rgbColor) {
    var color = "";
    if (typeof rgbColor === 'string') {//NO I18N
        color = rgbColor
    } else {
        color = "rgb("+rgbColor+")";//NO I18N
    }
    return color.replace(/^(rgb|rgba)\(/, '').replace(/\)$/, '').replace(/\s/g, '').split(',');//NO I18N
}

function luminance(r, g, b) {
      var a = [r, g, b].map(function(v) {
        v /= 255;
        return v <= 0.03928 ? v / 12.92 : Math.pow((v + 0.055) / 1.055, 2.4);
      });
      return a[0] * 0.2126 + a[1] * 0.7152 + a[2] * 0.0722;
}

function contrast(rgb1, rgb2) {
      var luminance1=(luminance(rgb1[0], rgb1[1], rgb1[2]) + 0.05);
      var luminance2=(luminance(rgb2[0], rgb2[1], rgb2[2]) + 0.05);
      if(luminance1>luminance2) {
          return luminance1/luminance2;
      }
      return luminance2/luminance1;
}

function convertTxtToHex(color) {
    var colours = {
    "aliceblue": "#f0f8ff", //No I18n
    "antiquewhite": "#faebd7", //No I18n
    "aqua": "#00ffff", //No I18n
    "aquamarine": "#7fffd4", //No I18n
    "azure": "#f0ffff", //No I18n
    "beige": "#f5f5dc", //No I18n
    "bisque": "#ffe4c4", //No I18n
    "black": "#000000", //No I18n
    "blanchedalmond": "#ffebcd", //No I18n
    "blue": "#0000ff", //No I18n
    "blueviolet": "#8a2be2", //No I18n
    "brown": "#a52a2a", //No I18n
    "burlywood": "#deb887", //No I18n
    "cadetblue": "#5f9ea0", //No I18n
    "chartreuse": "#7fff00", //No I18n
    "chocolate": "#d2691e", //No I18n
    "coral": "#ff7f50", //No I18n
    "cornflowerblue": "#6495ed", //No I18n
    "cornsilk": "#fff8dc", //No I18n
    "crimson": "#dc143c", //No I18n
    "cyan": "#00ffff", //No I18n
    "darkblue": "#00008b", //No I18n
    "darkcyan": "#008b8b", //No I18n
    "darkgoldenrod": "#b8860b", //No I18n
    "darkgray": "#a9a9a9", //No I18n
    "darkgreen": "#006400", //No I18n
    "darkkhaki": "#bdb76b", //No I18n
    "darkmagenta": "#8b008b", //No I18n
    "darkolivegreen": "#556b2f", //No I18n
    "darkorange": "#ff8c00", //No I18n
    "darkorchid": "#9932cc", //No I18n
    "darkred": "#8b0000", //No I18n
    "darksalmon": "#e9967a", //No I18n
    "darkseagreen": "#8fbc8f", //No I18n
    "darkslateblue": "#483d8b", //No I18n
    "darkslategray": "#2f4f4f", //No I18n
    "darkturquoise": "#00ced1", //No I18n
    "darkviolet": "#9400d3", //No I18n
    "deeppink": "#ff1493", //No I18n
    "deepskyblue": "#00bfff", //No I18n
    "dimgray": "#696969", //No I18n
    "dodgerblue": "#1e90ff", //No I18n
    "firebrick": "#b22222", //No I18n
    "floralwhite": "#fffaf0", //No I18n
    "forestgreen": "#228b22", //No I18n
    "fuchsia": "#ff00ff", //No I18n
    "gainsboro": "#dcdcdc", //No I18n
    "ghostwhite": "#f8f8ff", //No I18n
    "gold": "#ffd700", //No I18n
    "goldenrod": "#daa520", //No I18n
    "gray": "#808080", //No I18n
    "green": "#008000", //No I18n
    "greenyellow": "#adff2f", //No I18n
    "honeydew": "#f0fff0", //No I18n
    "hotpink": "#ff69b4", //No I18n
    "indianred ": "#cd5c5c", //No I18n
    "indigo": "#4b0082", //No I18n
    "ivory": "#fffff0", //No I18n
    "khaki": "#f0e68c", //No I18n
    "lavender": "#e6e6fa", //No I18n
    "lavenderblush": "#fff0f5", //No I18n
    "lawngreen": "#7cfc00", //No I18n
    "lemonchiffon": "#fffacd", //No I18n
    "lightblue": "#add8e6", //No I18n
    "lightcoral": "#f08080", //No I18n
    "lightcyan": "#e0ffff", //No I18n
    "lightgoldenrodyellow": "#fafad2", //No I18n
    "lightgrey": "#d3d3d3", //No I18n
    "lightgreen": "#90ee90", //No I18n
    "lightpink": "#ffb6c1", //No I18n
    "lightsalmon": "#ffa07a", //No I18n
    "lightseagreen": "#20b2aa", //No I18n
    "lightskyblue": "#87cefa", //No I18n
    "lightslategray": "#778899", //No I18n
    "lightsteelblue": "#b0c4de", //No I18n
    "lightyellow": "#ffffe0", //No I18n
    "lime": "#00ff00", //No I18n
    "limegreen": "#32cd32", //No I18n
    "linen": "#faf0e6", //No I18n
    "magenta": "#ff00ff", //No I18n
    "maroon": "#800000", //No I18n
    "mediumaquamarine": "#66cdaa", //No I18n
    "mediumblue": "#0000cd", //No I18n
    "mediumorchid": "#ba55d3", //No I18n
    "mediumpurple": "#9370d8", //No I18n
    "mediumseagreen": "#3cb371", //No I18n
    "mediumslateblue": "#7b68ee", //No I18n
    "mediumspringgreen": "#00fa9a", //No I18n
    "mediumturquoise": "#48d1cc", //No I18n
    "mediumvioletred": "#c71585", //No I18n
    "midnightblue": "#191970", //No I18n
    "mintcream": "#f5fffa", //No I18n
    "mistyrose": "#ffe4e1", //No I18n
    "moccasin": "#ffe4b5", //No I18n
    "navajowhite": "#ffdead", //No I18n
    "navy": "#000080", //No I18n
    "oldlace": "#fdf5e6", //No I18n
    "olive": "#808000", //No I18n
    "olivedrab": "#6b8e23", //No I18n
    "orange": "#ffa500", //No I18n
    "orangered": "#ff4500", //No I18n
    "orchid": "#da70d6", //No I18n
    "palegoldenrod": "#eee8aa", //No I18n
    "palegreen": "#98fb98", //No I18n
    "paleturquoise": "#afeeee", //No I18n
    "palevioletred": "#d87093", //No I18n
    "papayawhip": "#ffefd5", //No I18n
    "peachpuff": "#ffdab9", //No I18n
    "peru": "#cd853f", //No I18n
    "pink": "#ffc0cb", //No I18n
    "plum": "#dda0dd", //No I18n
    "powderblue": "#b0e0e6", //No I18n
    "purple": "#800080", //No I18n
    "rebeccapurple": "#663399", //No I18n
    "red": "#ff0000", //No I18n
    "rosybrown": "#bc8f8f", //No I18n
    "royalblue": "#4169e1", //No I18n
    "saddlebrown": "#8b4513", //No I18n
    "salmon": "#fa8072", //No I18n
    "sandybrown": "#f4a460", //No I18n
    "seagreen": "#2e8b57", //No I18n
    "seashell": "#fff5ee", //No I18n
    "sienna": "#a0522d", //No I18n
    "silver": "#c0c0c0", //No I18n
    "skyblue": "#87ceeb", //No I18n
    "slateblue": "#6a5acd", //No I18n
    "slategray": "#708090", //No I18n
    "snow": "#fffafa", //No I18n
    "springgreen": "#00ff7f", //No I18n
    "steelblue": "#4682b4", //No I18n
    "tan": "#d2b48c", //No I18n
    "teal": "#008080", //No I18n
    "thistle": "#d8bfd8", //No I18n
    "tomato": "#ff6347", //No I18n
    "turquoise": "#40e0d0", //No I18n
    "transparent": "#ffffff", //No I18n
    "violet": "#ee82ee", //No I18n
    "wheat": "#f5deb3", //No I18n
    "white": "#ffffff", //No I18n
    "whitesmoke": "#f5f5f5", //No I18n
    "yellow": "#ffff00", //No I18n
    "yellowgreen": "#9acd32" //No I18n
  };

  if (color && !color.toLowerCase().startsWith('rgb') && !color.toLowerCase().startsWith('#')) { //No I18n
    if (typeof colours[color.toLowerCase()] != 'undefined') { //No I18n
      return colours[color.toLowerCase()];
    }
  }
  return false;

}


function hexToRgb(hexColor) {
    if(hexColor && hexColor.startsWith("#")) { //NO I18N
        var shorthandRegex = /^#?([a-f\d])([a-f\d])([a-f\d])$/i;
        hexColor = hexColor.replace(shorthandRegex, function(m, r, g, b) {
          return r + r + g + g + b + b;
        });

        var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hexColor);
        return result ? 'rgb(' + parseInt(result[1], 16) + ',' + parseInt(result[2], 16) + ',' + parseInt(result[3], 16) + ')' : false; //No I18n

    }
    return false;
}


function enhanceReadabilityForLightTheme() {
    var elements = document.querySelectorAll('a,span,p,b,pre,li,font,div,table,td,tr,tbody,i,sub,sup,u,h1,h2,h3,h4,h5,h6,em,strong,ol,ul,li,br,BIG,SMALL,th,s,strike,center,form,tt,nobr,frame,frameset,dl,dt,dd,section'); //No I18n
    elements.forEach(function(element) {
        if(element.classList.contains('desk_change_bg')) {//NO I18N
            element.classList.remove('desk_change_bg');//NO I18N
        }

        if(element.classList.contains('desk_change_fg')) {//NO I18N
            element.classList.remove('desk_change_fg');//NO I18N
        }

        if(element.classList.contains('desk_change_fg_black')) {//NO I18N
            element.classList.remove('desk_change_fg_black');//NO I18N
        }
        
    })
}
