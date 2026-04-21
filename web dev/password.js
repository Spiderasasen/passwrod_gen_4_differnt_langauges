const submit_button = document.getElementById("submit");
const password_length = document.getElementById("password_length");
const password_option = document.getElementById("password_options");

submit_button.addEventListener("click", async () => {
    //confirmation that submit has been clicked
    console.log("Submit has been clicked!");

    //checking on the selctions
    console.log("User password length: ", password_length.value);
    console.log("User password option: ", password_option.value);

    //checking what option the user selcted
    switch (password_option.value) {
        case "a":
            console.log("Letters Only");

            const items = await opening_file("data/alphabet.txt");


            break;
        case "b":
            console.log("Numbers Only");
            break;
        case "c":
            console.log("Specials Only");
            break;
        case "d":
            console.log("All options");
            break;
        default:
            console.log("No selection");
    }
});

async function opening_file(filename){
    const response = await fetch(filename);
    const text = await response.text();
    return text.split("\n").map(line => line.trim()).filter(Boolean);
}