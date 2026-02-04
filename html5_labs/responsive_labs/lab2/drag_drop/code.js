const draggables = document.querySelectorAll('.draggable-item');
const dropZone = document.getElementById('drop-zone');
const container = document.getElementById('questions-container');

document.addEventListener('dragstart', (e) => {
        if (e.target.classList.contains('draggable-item')) {
            draggedNode = e.target;
            
            // Collect the label and icon class
            const transferData = {
                label: e.target.dataset.type,
                //icon: e.target.dataset.icon
            };
            
            e.dataTransfer.setData('application/json', JSON.stringify(transferData));
            e.target.style.opacity = '0.4';
        }
    });
    
draggables.forEach(item => {
    item.addEventListener('dragstart', (e) => {
        e.dataTransfer.setData('text/plain', item.getAttribute('data-type'));
    });
});

dropZone.addEventListener('dragover', (e) => {
    e.preventDefault();
    dropZone.classList.add('drag-over');
});

dropZone.addEventListener('dragleave', () => {
    dropZone.classList.remove('drag-over');
});

dropZone.addEventListener('drop', (e) => {
    e.preventDefault();
    dropZone.classList.remove('drag-over');
    
    const type = e.dataTransfer.getData('text/plain');
    addTheDiv(type);
});

function addTheDiv(type) {
    const div = document.createElement('div');
    div.className = 'added-question shadow-sm animate__animated animate__fadeIn';
    div.innerHTML = `<strong>${type}</strong>`;

    container.appendChild(div);
    dropZone.querySelector('span').innerText = "Drag more questions here";
}