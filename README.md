LearnFrom3D - 2D object classifier trained from 3D models
=========================================================


Train 2D object detector and classifier using data generated from 3D object models.


Requirements:
-------------

- a C++ compiler compatible with libraries below
- Qt with OpenGL for the UI and 3D model operations
- Darknet's YOLO neural network (standalone) for classifier training
- OpenCV for 2D image manipulations and making predictions with the classifier


Build:
------
```
mkdir bin
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make
make install
```
Replace the generator with one appropriate for your system.
The executable will be in `bin` folder.


Workflow (UI tabs):
-------------------

I. Generate 2D Projections from 3D Model.

 1. Load 3D model.
  - option to load texture
  - option to add background

 2. Transform
  - option for auto projection generation

 3. Save


II. Preprocess and Annotate 2D Projection Images to generate training data.

 1. Choose anotation format and options
  - YOLO format
  - Caffe
  - other formats...

 2. Annotate and save


III. Train ML Model on the 2D Images.
  - include and use YOLO as a library
  - YOLO: run darknet in training mode in a background process


IV. Predict. Apply ML Model to New Images.
  - load network architecture and weights and do forward pass with an image


ToDo:
-----

- support different 3D formats?
