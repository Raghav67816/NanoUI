Progress bar allows you to visualise status of a running operation in your application. This can also be used for different purposes based on your application development goals.


# ProgressBar::ProgressBar()

Params:

 - int w
 - int h

Creates an instance of label with specified labelText. If you are using layouts geometry might get modified relatives to the layout.

**Default max progress value is set to 100**

```cpp

ProgressBar prog_bar(40, 20);
```

# ProgressBar::getProgress()

Returns:
 - int currentProgress

Returns current progress value.

```cpp
...
int cProg = prog_bar.getProgress();
```

# ProgressBar::setProgress()

Params:

 - int value

Sets progress of the progress bar to the given value.

```cpp

prog_bar.setProgress(50); // set progress to 50%
```

# Events
 - PROGRESS_CHANGED

    This is triggered when progress is changed in the progress bar. The callback function must accept a float value as an argument.

Bind to this event by:

```
void onProgressChange(float val){
    // your logic when progress updates
};

prog_bar.bindEvent(PROGRESS_CHANGED, onProgressChanged);
```