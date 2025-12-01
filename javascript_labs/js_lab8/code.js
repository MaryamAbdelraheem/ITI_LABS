
let card = document.querySelector('.card');
let img = document.querySelector('#img');
let country = document.querySelector('#country');
let content = document.querySelector('#content');
let people = document.querySelector('#people');
let lang = document.querySelector('#lang');
let currency = document.querySelector('#currency');

class Card{
    constructor(){
        this.Card = card;
        this.img = img;
        this.country = country;
        this.content = content;
        this.people = people;
        this.lang = lang;
        this.currency = currency;

    }
    update(countryData){
        this.img.src = countryData.flags.png;
        this.country.innerHTML = countryData.name;
        this.content.innerHTML = countryData.capital;
        this.people.innerHTML = countryData.population;
        this.lang.innerHTML = countryData.languages[0].name;
        this.currency.innerHTML = countryData.currencies[0].name;
    }


}



const org_url = "https://restcountries.com/v2/name/%7bcountryname%7d";
const nrighbors_url = "https://restcountries.com/v2/alpha/%7Bneighbour%7D"



