const searchBtn = document.getElementById("search_btn");
const textInput = document.getElementById("text_input");
const cardsContainer = document.getElementById("cards-container");

searchBtn.addEventListener("click", () => {
    const countryName = textInput.value.trim();
    if (!countryName) return alert("Enter a country name!");

    cardsContainer.innerHTML = ""; 

    fetch(`https://restcountries.com/v2/name/${countryName}`)
        .then(res => {
            if (!(res.status == 200)) throw new Error("Country not found");
            return res.json();
        })
        .then(data => {
            const country = data[0];

            // country card
            const countryCard = document.createElement("div");
            countryCard.className = "country-card";
            countryCard.innerHTML = `
                <img src="${country.flag}" alt="Flag">
                <h2>${country.name}</h2>
                <p>${country.region}</p>
                <p>👥 ${(country.population/1e6).toFixed(1)} M People</p>
                <p>🗣 ${country.languages.map(l => l.name).join(", ")}</p>
                <p>💰 ${country.currencies.map(c => c.name).join(", ")}</p>
            `;
            cardsContainer.appendChild(countryCard);

            // neighbour country
            if (country.borders && country.borders.length > 0) {
                return fetch(`https://restcountries.com/v2/alpha/${country.borders[1]}`);
            } else {
                throw new Error("No neighbors found");
            }
        })
        .then(res => res.json())
        .then(neighbour => {
            const neighbourCard = document.createElement("div");
            neighbourCard.className = "country-card";
            neighbourCard.innerHTML = `
                <h4>NEIGHBOUR COUNTRY</h4>
                <img src="${neighbour.flag}" alt="Flag">
                <h2>${neighbour.name}</h2>
                <p>${neighbour.region}</p>
                <p>👥 ${(neighbour.population/1e6).toFixed(1)} M People</p>
                <p>🗣 ${neighbour.languages.map(l => l.name).join(", ")}</p>
                <p>💰 ${neighbour.currencies.map(c => c.name).join(", ")}</p>
            `;
            cardsContainer.appendChild(neighbourCard);
        })
        .catch(err => {
            cardsContainer.innerHTML += `<p style="color:red">${err.message}</p>`;
        });
});
