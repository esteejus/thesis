import plotly.graph_objects as go
from plotly.subplots import make_subplots
import pandas as pd
import numpy as np
from plotly.offline import iplot, init_notebook_mode
import matplotlib.pyplot as plt

#codes with all L values
theory = pd.read_csv('Pion_Multiplicity_Theory - Double Ratio.csv', sep=',')

theory_min = theory.reset_index()
theory_min = theory_min.loc[theory.groupby('name')['L'].idxmin()]

theory_max = theory.reset_index()
theory_max = theory_max.loc[theory.groupby('name')['L'].idxmax()]


print(theory_min)
custom_dict = {'AMD+JAM':3, "r'$\chi \text{BUU}$'":0, 'UrQMD':6, 'IQMD-BNU':5, 'SMASH':4, 'pBUU':2, 'TuQMD':1}

theory_min['rank'] = theory_min['name'].map(custom_dict)

theory_min.fillna(0, inplace=True)

theory_min.sort_values(by=['rank'], inplace=True)

print(theory_min)


fig = go.Figure()

#plot the soft double ratio
fig.add_trace(go.Scatter(
        x = theory_min.name,
        y = theory_min.doubleratio,
        name = 'Soft',
        marker=dict(
        #color='rgba(156, 165, 196, 0.95)',
        color='lightblue',
        line_color='lightgray',
        ))
)

#plot the stiff double ratio
fig.add_trace(go.Scatter(
        x = theory_max.name,
        y = theory_max.doubleratio,
        name = 'Stiff',
        marker=dict(
        #color='rgba(156, 165, 196, 0.95)',
        color='lightpink',
        line_color='lightgray',
        ))
)



# Add mean line for data measurment

doubleratio = 2.42299

#error bars
err_doubleratio = .046775

y0 = -.5
y1 = 6.5


#rectangle represents error bar
fig.add_shape(type="rect", fillcolor='blue', opacity=.3, xref="x1", yref="y1",
            y0=doubleratio-err_doubleratio, x0=y0, y1=doubleratio+err_doubleratio, x1=y1)
        
        #lines represent mean value of measurment
fig.add_shape(type="line", xref="x1", yref="y1",
            y0=doubleratio, x0=y0, y1=doubleratio, x1=y1, line_width=3)

fig.update_traces(mode='markers', marker=dict(line_width=1, symbol='circle', size=26))

fig.update_layout(
    title="",
     yaxis=dict(
         range=[1.6,2.8],
        showgrid=False,
        showline=True,
        linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        dtick=.5,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)',
    ),
    xaxis=dict(
        showgrid=True,
        showline=True,
        gridcolor='lightgray',
        linecolor='rgb(102, 102, 102)',
        tickfont_color='rgb(102, 102, 102)',
        showticklabels=True,
        ticks='outside',
        tickcolor='rgb(102, 102, 102)',
    ),
    margin=dict(l=140, r=40, b=50, t=80),
    legend=dict(
        font_size=20,
        yanchor='middle',
        xanchor='right',
    ),
    width=800,
    height=600,
    paper_bgcolor='white',
    plot_bgcolor='white',
    hovermode='closest',
    xaxis_title="",
    yaxis_title="r'$R_{132+124}/R_{108+112}$",
    font=dict(
        family="Courier New, monospace",
        size=24,
        color="#7f7f7f"
    )
)
#fig.write_image("pionpaper_horz_lin.pdf")

fig.show()
