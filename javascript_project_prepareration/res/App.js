import React, { useState } from 'react';
import './App.css';

const qaData = [
  { question: "What language is React based on?", answer: "JavaScript" },
  { question: "What are the building blocks of React apps?", answer: "Components" },
  { question: "What's the name of the syntax we use to describe a UI in React?", answer: "JSX" },
  { question: "How to give components memory?", answer: "State" },
  { question: "What do we call an input element that is completely synchronised with state?", answer: "Controlled Component" },
  { question: "Props", answer: "Props are used to pass data from one component to another." },
  { question: "What is the concept of 'Virtual DOM' in React?", answer: "Virtual DOM is a JavaScript representation of the actual DOM. It allows React to efficiently update only the necessary parts of the UI, reducing the number of re-renders and improving performance." },
  { question: "What is the difference between 'Class Components' and 'Functional Components' in React?", answer: "Class components use ES6 classes and have access to additional features like state, lifecycle methods, and local variables. Functional components, on the other hand, are functions that accept props and return JSX. They are simpler and easier to understand, but they lack some of the features available in class components." },
  { question: "What is the purpose of 'React Hooks'?", answer: "React Hooks allow you to use state and other React features without writing class components. They provide a more flexible and efficient way to manage state and handle side effects in functional components." },
  { question: "What is the 'Context API' in React?", answer: "The Context API allows you to share data across multiple components without passing props down manually. It provides a way to create global state that can be accessed by any component in the application." },
  { question: "What is the 'React Router' library used for?", answer: "React Router is a library that allows you to create navigation and routing in React applications. It provides components for defining routes, navigating between routes, and handling URL parameters." },
  { question: "What is the 'useCallback' hook used for?", answer: "The useCallback hook returns a memoized version of a callback function that only changes if one of the dependencies has changed. This can help optimize performance by preventing unnecessary re-renders when the callback is passed as a prop to child components." },
];

function App() {
  return (
    <div className="card-container">
      {qaData.map((qa, index) => (
        <Card key={index} question={qa.question} answer={qa.answer} />
      ))}
    </div>
  );
}

const Card = ({ question, answer }) => {
  const [showAnswer, setShowAnswer] = useState(false);

  return (
    <div
      className={`card ${showAnswer ? 'card-answer' : 'card-question'}`}
      onClick={() => setShowAnswer(!showAnswer)}
    >
      <p>{showAnswer ? answer : question}</p>
    </div>
  );
}

export default App;
