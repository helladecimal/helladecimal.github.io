// FILE:  -->
// FOLDER:  -->

// └─       ├─      │

let folderIcon = document.createElement("span");
folderIcon.innerHTML = "";
folderIcon.className = "nerd";

let fileIcon = document.createElement("span");
fileIcon.innerHTML = "";
fileIcon.className = "nerd";

let endBracket = document.createElement("span");
endBracket.innerHTML = "└─ ";
endBracket.className = "bracket";

let bracket = document.createElement("span");
bracket.innerHTML = "├─ ";
bracket.className = "bracket";

let pipe = document.createElement("span");
pipe.innerHTML = "│";
pipe.className = "pipe";

let folders = document.querySelectorAll(".folder");

let files = document.querySelectorAll(".file");

let items = document.querySelectorAll(".file, .folder");

folders.forEach(function(folder){
    folder.prepend(folderIcon.cloneNode(true));

    if (folder.id !== "root"){
        if (folder !== folder.parentElement.lastElementChild){
            folder.prepend(bracket.cloneNode(true));
        } else {
            folder.prepend(endBracket.cloneNode(true));
        }
    }
});

files.forEach(function(file){
    file.prepend(fileIcon.cloneNode(true));
    
    if (file !== file.parentElement.lastElementChild){
        file.prepend(bracket.cloneNode(true));
    } else {
        file.prepend(endBracket.cloneNode(true));
    }

});

items.forEach(function(item){
    let depth = 0;
    let parent = item.parentElement;

    while (parent && parent.id !== "root" && item.id !== "root"){
        depth++;
        parent = parent.parentElement;
    }

    console.log(depth, item.innerText)

    if (depth > 0){

        for (let i=depth; i > 0; i--){ 
            let localPipe = pipe.cloneNode(true);
            item.prepend(localPipe);
            localPipe.style.right = (2.5*i) + "ch";
        };
    };
});

